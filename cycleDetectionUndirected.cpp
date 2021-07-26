#include <bits/stdc++.h>

using namespace std;

bool detectCycle(vector<int> *adj, int i, vector<bool> &visited, int parent)
{
    visited[i] = true;

    for (auto nbr : adj[i])
    {
        if (!visited[nbr])
        {
            bool nextElement = detectCycle(adj, nbr, visited, i);
            if (nextElement)
                return true;
        }
        else if (parent != nbr)
        {
            return true;
        }
    }

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
        adj[y].push_back(x);
    }

    vector<bool> visited(n, false);

    cout << detectCycle(adj, 0, visited, -1);

    return 0;
}