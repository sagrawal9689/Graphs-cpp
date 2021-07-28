#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    vector<int> distTo(V, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    distTo[S] = 0;

    Q.push({0, S});

    while (!Q.empty())
    {
        int prev = Q.top().second;
        int preDist = Q.top().first;
        Q.pop();

        for (auto nbr : adj[prev])
        {
            int next = nbr[0];
            int nextDist = nbr[1];

            if (distTo[next] > nextDist + preDist)
            {
                distTo[next] = nextDist + preDist;
                Q.push({distTo[next], next});
            }
        }
    }
}