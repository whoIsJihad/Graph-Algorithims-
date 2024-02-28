#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define iPair pair<int, int>
#define ll long long int
using namespace std;

void BFS(int source, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &bfs)
{
    visited[source] = true;
    queue<int> q;

    q.push(source);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        bfs.push_back(x);
        for (auto neighbour : graph[x])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

void DFS(int source, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &dfs)
{
    visited[source] = true;
    dfs.push_back(source);

    for (auto neighbour : graph[source])
    {
        if (!visited[neighbour])
            DFS(neighbour, graph, visited, dfs);
    }
}

int main()
{
    int n, m;
    // N vertex, M edges

    cin >> n >> m;

    // creating undirected and directed Graph
    vector<vector<int>> UnGraph(n);
    vector<vector<int>> DiGraph(n);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        // directed

        DiGraph[x].push_back(y);

        // undirected
        UnGraph[x].push_back(y);
        UnGraph[y].push_back(x);
    }

    vector<int> bfs;
    vector<bool> visited;
    visited.resize(n, false); // Correct: Set the size and initialize with false values
    BFS(0, DiGraph, visited, bfs);

    cout << "bfs in directed Graph: ";
    for (auto x : bfs)
        cout << x << " ";

    bfs.clear();
    visited.assign(n, false); // Correct: Reinitialize with false values
    BFS(0, UnGraph, visited, bfs);

    cout << "\nbfs in undirected Graph: ";
    for (auto x : bfs)
        cout << x << " ";

    vector<int> dfs;
    visited.assign(n, false); // Correct: Reinitialize with false values
    DFS(0, DiGraph, visited, dfs);

    cout << "\ndfs in directed Graph: ";
    for (auto x : dfs)
        cout << x << " ";

    dfs.clear();
    visited.assign(n, false); // Correct: Reinitialize with false values
    DFS(0, UnGraph, visited, dfs);

    cout << "\ndfs in undirected Graph: ";
    for (auto x : dfs)
        cout << x << " ";

    return 0;
}
