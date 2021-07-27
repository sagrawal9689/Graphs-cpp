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

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    vector<bool> visited(n + 1, false);

    Q.push({0, 1});

    long long ans = 0;

    while (!Q.empty())
    {
        auto best = Q.top();
        Q.pop();

        int weight = best.first;
        int to = best.second;

        if (visited[to])
            continue;

        visited[to] = true;

        ans += (long long)weight;

        for (auto nbr : adj[to])
        {
            if (!visited[nbr.first])
                Q.push({nbr.second, nbr.first});
        }
    }

    cout << ans;

    return 0;
}