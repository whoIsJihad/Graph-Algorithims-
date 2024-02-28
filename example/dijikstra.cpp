#include <bits/stdc++.h>
#define iPair pair<long long int, long long int>
using namespace std;

vector<vector<pair<long long int, long long int>>> buildGraphW()
{
    long long int m, n;
    cin >> n >> m;
    vector<vector<pair<long long int, long long int>>> Graph(n);

    for (long long int i = 0; i < m; i++)
    {
        long long int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        Graph[x].push_back({y, w});
        Graph[y].push_back({x, w});
    }
    return Graph;
}

vector<long long int> SSSP_dijistra(vector<vector<iPair>>& graph, long long int src, vector<long long int> &parent)
{
    long long int n = graph.size();

    vector<long long int> dist(n,INT_MAX);

    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    dist[src] = 0;
    // pushing the src in the heap
    pq.push({0, src});

    while (!pq.empty())
    {
        auto mini = pq.top();
        pq.pop();

        long long int minNode = mini.second;
        if(dist[minNode]!= mini.first) continue;


        for (auto &edgeFromMini : graph[minNode])
        {
            long long int u = minNode;
            long long int v = edgeFromMini.first;
             long long int w = edgeFromMini.second;

            if (dist[u] + w < dist[v])
            {

                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
    return dist;
}

 int main()
{

    long long int m, n;
    cin >> n >> m;
    vector<vector<pair<long long int, long long int>>> Graph(n);

    for (long long int i = 0; i < m; i++)
    {
        long long int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        Graph[x].push_back({y, w});
        Graph[y].push_back({x, w});
    }

    vector<long long int> parent(n, -1);

    vector<long long int> dist = SSSP_dijistra(Graph, 0, parent);
    long long int i = n - 1;
    stack<long long int> st;

    if (parent[n - 1] == -1LL)
    {
        cout << -1 << " ";
        return 0;
    }

    while (i != -1)
    {
        st.push(i + 1);
        i = parent[i];
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
