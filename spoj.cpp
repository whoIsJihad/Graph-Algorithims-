#include <bits/stdc++.h>
#define M 1000000000
using namespace std;

bool customComparator(vector<int> &v1, vector<int> &v2)
{
    return v1[2] < v2[2];
}

class DS
{
    vector<int> parent;
    vector<int> rank;

public:
    DS(int v)
    {
        parent.assign(v,0);
        rank.assign(v,0);
        for (int i = 0; i < v; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    // finding the representative element
    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    // union by path compression

    void Union(int a, int b)
    {
        int sa = find(a);
        int sb = find(b);

        if (sa != sb)
        {
            if (rank[sa] > rank[sb])
            {
                parent[sb] = sa;
            }
            else if (rank[sa] < rank[sb])
            {
                parent[sa] = sb;
            }

            else
            {
                parent[sa] = sb;
                rank[sb]++;
            }
        }
    }
};

int solve(vector<vector<int>> &Edges, int v, int a, int b)
{
    sort(Edges.begin(), Edges.end(), customComparator);
    int ans = 0;

    DS ds(v);

    int i = 0;
    while (ds.find(a) != ds.find(b))
    {
        int nodeOne = Edges[i][0];
        int nodeTwo = Edges[i][1];
        int weight = Edges[i][2];

        ds.Union(nodeOne, nodeTwo);
        ans = ans + weight;
        i++;
    }
    return ans;
}

int main()
{
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> Edges;
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        Edges.push_back({x, y, z});
    }
    vector<vector<int>>costs(n,vector<int>(n,0));

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j &&i<j)
            {
                costs[i][j]=solve(Edges,n,i,j);
                
                ans = (ans % M + (costs[i][j] % M)) % M;
            }
        }
    }
    cout<<ans;
}