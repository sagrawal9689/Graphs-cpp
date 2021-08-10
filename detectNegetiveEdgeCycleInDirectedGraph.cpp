int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{

    int ans = false;

    //create a dist array
    vector<int> dist(n, INT_MAX);

    dist[0] = 0;

    // relax all edges n-1 times
    for (int i = 0; i < n - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (dist[u] != INT_MAX && dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // check for neg edge cycle

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        if (dist[u] != INT_MAX && dist[v] > dist[u] + weight)
        {
            ans = true;
            dist[v] = dist[u] + weight;
        }
    }
    return ans;
}