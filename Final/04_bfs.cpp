#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> bfsOfGraph(int V, vector<vector<int>> &adjMatrix)
{
    queue<int> qt;
    unordered_map<int, bool> visited;
    vector<int> ans;

    qt.push(0);
    visited[0] = true;
    ans.push_back(0);

    while (!qt.empty())
    {
        int t = qt.front();
        qt.pop();

        for (int i = 0; i < V; i++)
        {
            if (adjMatrix[t][i] == 1 && !visited[i])
            {
                ans.push_back(i);
                visited[i] = true;
                qt.push(i);
            }
        }

        if (ans.size() == V)
        {
            break;
        }
    }

    return ans;
}
int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    vector<int> ans = bfsOfGraph(V, adjMatrix);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}
