#include <bits/stdc++.h>

using namespace std;

void bfs(int source, vector<int> *adj, vector<bool> &visited, vector<int> &parent, vector<int> &distance)
{
    queue<int> pendingNodes;
    pendingNodes.push(source);
    visited[source] = true;

    parent[source] = source;
    distance[source] = 0;

    while (!pendingNodes.empty())
    {
        int front = pendingNodes.front();
        pendingNodes.pop();

        cout << front << " ";

        for (int nbr : adj[front])
        {
            if (!visited[nbr])
            {
                pendingNodes.push(nbr);
                visited[nbr] = true;
                parent[nbr] = front;
                distance[nbr] = distance[front] + 1;
            }
        }
    }
}

void printAdj(vector<int> *adj, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";

        for (int nbr : adj[i])
            cout << nbr << " ";

        cout << "\n";
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj[n];
    vector<bool> visited(n, false);

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    printAdj(adj, n);

    vector<int> parent(n);
    vector<int> distance(n);

    bfs(0, adj, visited, parent, distance);

    cout << "\n";

    for (int i = 0; i < n; i++)
        cout << parent[i] << " ";

    cout << "\n";

    for (int i = 0; i < n; i++)
        cout << distance[i] << " ";
}