#include <bits/stdc++.h>

using namespace std;

class Person {
public:
    int height;
    int age;
    int maritalStatus;
};

int BreadthFirstSearch(int source, int sink, vector<int> &parent, vector<vector<int>> &adj, vector<vector<int>> &capacity)
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

int FordFulkerson(int source, int sink, vector<vector<int>> &adj, vector<vector<int>> &capacity)
{
    int maxFlow = 0;

    vector<int> parent;
    int newFlow;

    while ((newFlow = BreadthFirstSearch(source, sink, parent, adj, capacity)) > 0)
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
    int numMen, numWomen;
    cin >> numMen >> numWomen;

    vector<Person> men(numMen);
    vector<Person> women(numWomen);

    for (int i = 0; i < numMen; i++)
    {
        int h, a, d;
        cin >> h >> a >> d;
        men[i].height = h;
        men[i].age = a;
        men[i].maritalStatus = d;
    }
    for (int i = 0; i < numWomen; i++)
    {
        int h, a, d;
        cin >> h >> a >> d;
        women[i].height = h;
        women[i].age = a;
        women[i].maritalStatus = d;
    }

    // building the flow network
    vector<vector<int>> capacity(numWomen + numMen + 2, vector<int>(numWomen + numMen + 2, 0));
    vector<vector<int>> adjacencyList(numMen + numWomen + 2);

    // connecting males with the source :)
    for (int i = 1; i <= numMen; i++)
    {
        adjacencyList[0].push_back(i);
        adjacencyList[i].push_back(0);
        capacity[0][i] = 1;
    }

    // connecting females with the sink :(
    for (int i = numMen + 1; i <= numWomen + numMen; i++)
    {
        adjacencyList[i].push_back(numWomen + numMen + 1);
        adjacencyList[numWomen + numMen + 1].push_back(i);
        capacity[i][numWomen + numMen + 1] = 1;
    }

    // connecting matches
    for (int i = 0; i < numMen; i++)
    {
        for (int j = 0; j < numWomen; j++)
        {
            bool condition1 = abs(men[i].height - women[j].height) <= 10;
            bool condition2 = abs(men[i].age - women[j].age) <= 5;
            bool condition3 = !(men[i].maritalStatus ^ women[j].maritalStatus);

            if (condition1 && condition2 && condition3)
            {
                adjacencyList[i + 1].push_back(j + numMen + 1);
                adjacencyList[j + numMen + 1].push_back(i + 1);
                capacity[i + 1][j + numMen + 1] = 1;
            }
        }
    }

    cout << FordFulkerson(0, numMen + numWomen + 1, adjacencyList, capacity);
}
