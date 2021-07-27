#include <bits/stdc++.h>

using namespace std;

int find_set(int v, vector<int> &parent)
{
    if (parent[v] == -1)
        return v;

    // path compression by storing parent[v]

    return parent[v] = find_set(parent[v], parent);
}

// above path compression make TC of find and union to o(logn)

void union_set(int i, int j, vector<int> &parent, vector<int> &rank)
{
    int s1 = find_set(i, parent);
    int s2 = find_set(j, parent);

    if (s1 != s2)
    {
        // union by rank makes TC of find and union to almost O(1)

        if (rank[s1] < rank[s2])
        {
            parent[s1] = s2;
            rank[s2] += rank[s1];
        }
        else
        {
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    bool hasCycle = false;
    vector<int> parent(n, -1);
    vector<int> rank(n, 1);

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;

        int s1 = find_set(x, parent);
        int s2 = find_set(y, parent);

        if (s1 == s2)
        {
            hasCycle = true;
        }
        else
        {
            union_set(s1, s2, parent, rank);
        }
    }
}
