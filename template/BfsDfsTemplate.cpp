#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//takes in source,adjacency list,visited array,bfs vector to store the result
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
//takes in source,adjacency list,visited array,dfs vector to store the result

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

