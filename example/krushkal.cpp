#include <bits/stdc++.h>

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
        parent.resize(v);
        rank.resize(v);
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

int krushkal(vector<vector<int>>&Edges,int v){
    sort(Edges.begin(),Edges.end(),customComparator);
    int ans=0;

    DS ds(v);

    for(auto edge:Edges){
        int nodeOne=edge[0];
        int nodeTwo=edge[1];
        int weight=edge[2];

        if(ds.find(nodeOne)!=ds.find(nodeTwo)){
            ds.Union(nodeOne,nodeTwo);
            ans+=weight;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> edgeList;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edgeList.push_back({x, y, z});
    }
}