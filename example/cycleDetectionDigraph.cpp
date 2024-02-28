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
        // Graph[y].push_back(x);
    }
    return Graph;
}
bool cycle(int source,vector<vector<int>>&graph,vector<bool>&visited,vector<bool>&recursionStack){
    visited[source]=true;
    recursionStack[source]=true;

    for(auto x:graph[source]){
        if(visited[x]&& recursionStack[x]) return true;
        else if(!visited[x]){
            return cycle(x,graph,visited,recursionStack);
        }
    }
    recursionStack[source]=false;
    return false;
}

bool cycleOrNot(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<bool> recursionStack(n, false);

    for(int i=0;i<graph.size();i++){
        if(!visited[i]&& cycle(i,graph,visited,recursionStack))return true;
    }
    return false;
}

int main()
{

    vector<vector<int>> Graph = buildGraph();
    if(cycleOrNot(Graph)) cout<<"Cycle exists";
    else cout<<"Cycle doesnt exist";
}