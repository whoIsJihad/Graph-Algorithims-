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


vector<vector<pair<int,int>>>buildGraphW(){
    int m,n;
    cin>>n>>m;
    vector<vector<pair<int,int>>>Graph(n);

    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        Graph[x].push_back({y,w});
        Graph[y].push_back({x,w});
    }
    return Graph;

}