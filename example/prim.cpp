#include <bits/stdc++.h>
#define iPair pair<int, int>
using namespace std;
vector<vector<pair<int, int>>> buildGraphW()
{
    int m, n;
    cin >> n >> m;
    vector<vector<pair<int, int>>> Graph(n);

    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        Graph[x].push_back({y, w});
        Graph[y].push_back({x, w});
    }
    return Graph;
}
int primsAlgo(vector<vector<pair<int, int>>> &graph, int src = 0)
{
    int n = graph.size();
    int mstval = 0;

    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);

    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    key[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto mini = pq.top();
        pq.pop();
        int miniNode = mini.second;
        if (mst[miniNode])
            continue;
        mst[miniNode] = true;
        mstval += mini.first;

        for (auto x : graph[miniNode])
        {
            if (key[x.first] > x.second && mst[x.first] == false)
            {
                key[x.first] = x.second;
                pq.push({key[x.first], x.first});
                parent[x.first] = miniNode;
            }
        }
    }
    return mstval;
}

int main()
{
    vector<vector<iPair>> graph = buildGraphW();

    cout << primsAlgo(graph);
}