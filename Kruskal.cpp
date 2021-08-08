#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int from, to, weight;
    Edge(int f, int t, int w)
    {
        from = f;
        to = t;
        weight = w;
    }
};

static bool cmp(Edge &a, Edge &b)
{
    return a.weight < b.weight;
}

int find_set(int v, vector<int> &parent)
{
    if (parent[v] == -1)
        return v;

    return parent[v] = find_set(parent[v], parent);
}

int union_set(int x, int y, vector<int> &parent)
{
    int s1 = find_set(x, parent);
    int s2 = find_set(y, parent);

    if (s1 != s2)
    {
        parent[s1] = s2;
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<Edge> edges;

    for (int i = 0; i < V; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        Edge e(x, y, z);
        edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(V, -1);

    int cnt = 0;
    int ans = 0;

    for (Edge e : edges)
    {
        int s1 = find_set(e.from, parent);
        int s2 = find_set(e.to, parent);

        if (s1 != s2)
        {
            union_set(s1, s2, parent);
            cnt++;
            ans += e.weight;

            // cout<<e.weight<<" ";
        }

        if (cnt == (V - 1))
            break;
    }

    cout << ans << "\n";

    return 0;
}