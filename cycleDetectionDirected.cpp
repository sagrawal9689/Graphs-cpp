#include <bits/stdc++.h>

using namespace std;

bool detectCycle(vector<int> *adj, int source, vector<bool> &visited, vector<bool> &stack)
{
    visited[source] = true;
    stack[source] = true;

    for (auto nbr : adj[source])
    {
        if (stack[nbr])
        {
            return true;
        }
        else if (!visited[nbr])
        {
            bool nbrFoundACycle = detectCycle(adj, nbr, visited, stack);
            if (nbrFoundACycle)
                return true;
        }
    }

    stack[source] = false;
    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj[n];

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
    }

    vector<bool> visited(n, false);
    vector<bool> stack(n, false);

    bool ans = false;

    for (int i = 0; i < n; i++)
    {
        int source = i;
        if (!visited[i])
        {
            if (detectCycle(adj, source, visited, stack))
                ans = true;
        }
    }
    cout << ans;

    return 0;
}