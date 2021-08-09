#include <bits/stdc++.h>

using namespace std;

void dfs(int curr, vector<bool> &visited, vector<int> adj[], vector<int> &disc, vector<int> &low, int parent)
{
    visited[curr] = true;
    disc[curr] = low[curr] = t++;

    // cout<<curr<<" ";

    for (int nbr : adj[curr])
    {
        if (!visited[nbr])
        {
            dfs(nbr, visited, adj, disc, low, curr);

            low[curr] = min(low[curr], low[nbr]);

            if (low[nbr] > disc[curr])
            {
                // we found a bridge
                // bridge.push(nbr,curr);
            }
        }
        else if (nbr != parent)
        {
            low[curr] = min(low[curr], disc[nbr]);
        }
    }
}

int main()
{
    int V, e;
    cin >> V >> e;

    vector<int> adj[V];
    vector<bool> visited(V, false);

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> disc(V);
    vector<int> low(V);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, visited, adj, disc, low, -1);
    }

    return 0;
}