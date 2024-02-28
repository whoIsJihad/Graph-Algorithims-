#include <bits/stdc++.h>

using namespace std;

void printVec(vector<vector<int>> &v)
{
    cout << endl;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j]==INT_MAX) cout<<"INTMAX\t";
            else cout << v[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> D(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++)
        D[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        D[x][y] = w;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (D[i][k] != INT_MAX && D[k][j] != INT_MAX)
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
        printVec(D);
    }
}
/*
4 6
0 1 3
1 2 2
1 3 3
2 0 3
2 3 -5 
3 0 6
*/ 