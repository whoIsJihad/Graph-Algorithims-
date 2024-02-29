#include <bits/stdc++.h>

using namespace std;

int BFS(int source, int sink, vector<int> &parent, vector<vector<int>> &adj, vector<vector<int>> &capacity)
{
    int numVertices = adj.size();
    parent.assign(numVertices, -1);
    parent[source] = -2;

    queue<pair<int, int>> q;
    q.push({source, INT_MAX});

    while (!q.empty())
    {
        int current = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[current])
        {
            if (parent[next] == -1 && capacity[current][next] != 0)
            {
                parent[next] = current;
                int newFlow = min(flow, capacity[current][next]);
                if (next == sink)
                    return newFlow;
                q.push({next, newFlow});
            }
        }
    }
    return 0;
}

int DFS(int start, vector<vector<int>> &adj, vector<vector<int>> &capacity, vector<bool> &visited)
{
    visited[start] = true;

    for (int next : adj[start])
    {
        if (!visited[next] && capacity[start][next])
            DFS(next, adj, capacity, visited);
    }
}

int FordFulkenson(int source, int sink, vector<vector<int>> &adj, vector<vector<int>> &capacity)
{
    int maxFlow = 0;

    vector<int> parent;
    int newFlow;

    while ((newFlow = BFS(source, sink, parent, adj, capacity)) > 0)
    {
        maxFlow = maxFlow + newFlow;
        int current = sink;
        while (current != source)
        {
            int previous = parent[current];
            capacity[previous][current] -= newFlow;
            capacity[current][previous] += newFlow;
            current = previous;
        }
    }
    return maxFlow;
}

int main()
{
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    vector<vector<int>> initialCapacities;
    vector<vector<int>> capacityMatrix(numVertices, vector<int>(numVertices, 0));
    vector<vector<int>> adjacencyList(numVertices);

    for (int i = 0; i < numEdges; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        capacityMatrix[x][y] = c;
        adjacencyList[x].push_back(y);
        adjacencyList[y].push_back(x);
    }
    initialCapacities = capacityMatrix;

    int source, sink;
    cin >> source >> sink;
    source--;
    sink--;

    int maxFlowValue = FordFulkenson(source, sink, adjacencyList, capacityMatrix);
    vector<int> vertexFlows(numVertices);
    for (int i = 0; i < numVertices; i++)
    {
        if (i != sink && i != source)
        {
            int flow = 0;
            for (int j = 0; j < numVertices; j++)
            {
                if (initialCapacities[i][j])
                    flow += initialCapacities[i][j] - capacityMatrix[i][j];
            }
            vertexFlows[i] = (flow);
        }
    }

    int maxVertex = 0;
    int maxFlow = -1;
    for (int i = 0; i < numVertices; i++)
    {
        if (vertexFlows[i] > maxFlow && i != source && i != sink)
        {
            maxVertex = i;
            maxFlow = vertexFlows[i];
        }
    }
    cout << maxVertex + 1 << " " << maxFlow << endl;

    // min Cut
    vector<bool> visitedNodes(numVertices, false);
    DFS(source, adjacencyList, capacityMatrix, visitedNodes);

    cout << "[ { ";
    for (int i = 0; i < numVertices; i++)
    {
        if (visitedNodes[i])
            cout << i + 1 << " , ";
    }
    cout << " }, { ";
    for (int i = 0; i < numVertices; i++)
    {
        if (!visitedNodes[i])
            cout << i + 1 << " , ";
    }
    cout << "} ]";
}
