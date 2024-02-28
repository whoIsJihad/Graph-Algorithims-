#include <bits/stdc++.h>

using namespace std;

//for directed graph
//to apply for undirected graph , add edges u,v,w and v,u,w

vector<int> SSSP_BF(vector<vector<int>> edgeList, int n, int src)
{
    vector<int> d(n, INT_MAX);
    d[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < edgeList.size(); j++)
        {
            int nodeOne = edgeList[j][0];
            int nodeTwo = edgeList[j][1];
            int w = edgeList[j][2];

            if (d[nodeOne] != INT_MAX)
                d[nodeTwo] = min(d[nodeTwo], d[nodeOne] + w);
        }
    }
    return d;
}

int main()
{
    int m, n;
    cin >> n >> m;
    vector<vector<int>> edgeList;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edgeList.push_back({x, y, z});
    }

    vector<int>dist=SSSP_BF(edgeList,n,0);

    for(auto x:dist) cout<<x<<" ";
}