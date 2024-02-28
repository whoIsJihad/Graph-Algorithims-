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
        x--;
        y--;
        Graph[x].push_back({y, w});
        Graph[y].push_back({x, w});
    }
    return Graph;
}

vector<int> SSSP_dijistra(vector<vector<iPair>> &graph, int src)
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

        for (auto &edgeFromMini : graph[minNode])
        {
            int u = minNode;
            int v = edgeFromMini.first;
            int w = edgeFromMini.second;

            if (dist[u] + w < dist[v])
            {

                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                //parent[v] = u;
            }
        }
    }
    return dist;
}

int main()
{

    int m, n;
    cin >> n >> m;
    vector<vector<pair<int, int>>> Graph(2 * n);

    for (int i = 1; i <= n; i++)
    {
        Graph[2 * i - 1].push_back({2 * i - 2, 1});
        Graph[2 * i - 2].push_back({2 * i - 1, 1});
    }

    for (int i = 0; i < m; i++)
    {
        // x is the down city,y is the up city
        int x, y;
        cin >> x >> y;
        // we can go from (x,upward) to (y,upward)
        Graph[2 * x - 2].push_back({2 * y - 2, 0});

        //we can go from (y,down) to (x,down)
        Graph[2 * y - 1].push_back({2 * x - 1, 0});

    }
    int s,d;
    cin>>s>>d;

    vector<int> ansOne=SSSP_dijistra(Graph,2*s-1); //source down
    vector<int> ansTwo=SSSP_dijistra(Graph,2*s-2);  //source up

    int d1=min(ansOne[2*d-1],ansOne[2*d-2]);
    int d2=min(ansTwo[2*d-1],ansTwo[2*d-2]);

    cout<<min(d1,d2);


}
