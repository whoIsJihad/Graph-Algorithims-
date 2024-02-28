#include<bits/stdc++.h>
#define iPair pair<int, int>
using namespace std;

//takes input adjacentcy list and returns the dist vector from src

vector<int> SSSP_dijistra(vector<vector<iPair>> graph, int src)
{
    int n = graph.size();

    vector<int> dist(n, INT_MAX);

    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    dist[src] = 0;
    // pushing the src in the heap
    pq.push({0, src});

    while (!pq.empty())
    {
        auto mini = pq.top();
        pq.pop();

        int minNode = mini.second;

        for (auto edgeFromMini : graph[minNode])
        {
            int u = minNode;
            int v = edgeFromMini.first;
            int w = edgeFromMini.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
