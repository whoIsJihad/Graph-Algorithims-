#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> buildGraph()
{
    int m, n;

    cin >> n >> m;
    vector<vector<int>> Graph(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }
    return Graph;
}
bool cycleUtil(int source, vector<vector<int>> &graph, vector<bool> &visited,vector<int>&parent)
{
    queue<int>q;
    visited[source]=true;
    q.push(source);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto y:graph[x]){
            if(!visited[y]){
                visited[y]=true;
                q.push(y);
                parent[y]=x;
            }
            else if(visited[y]&& parent[x]!=y)return true;
        }
    }
    return false;
}
bool checkCycle(vector<vector<int>> &Graph)
{
    int n = Graph.size();
    vector<bool> visited(n, false);
    vector<int>parent(n,-1);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && cycleUtil(i, Graph,visited,parent))return true;
    }
    return false;
}

int main()
{

    vector<vector<int>> Graph = buildGraph();

    if(checkCycle(Graph)) cout<<"Cycle exist";
    else cout<<"Cycle doesnt exist";
}