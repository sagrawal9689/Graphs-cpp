#include <bits/stdc++.h>

using namespace std;

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

    vector<int> ans;

    vector<int> indegree(n, 0);

    // Calculate indegree for all nodes

    for (int i = 0; i < n; i++)
    {
        for (auto nbr : adj[i])
        {
            indegree[nbr]++;
        }
    }
    queue<int> q;

    // add those node to queue having 0 in degree

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    //remove each element from queue and decrease indegree of their child and add the child to queue if indegree becomes 0

    while (!q.empty())
    {
        int front = q.front();
        ans.push_back(front);
        q.pop();

        for (auto nbr : adj[front])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
                q.push(nbr);
        }
    }

    // at the end we must have n nodes in ans vector

    //if(ans.size()==n)
    //return ans;

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}