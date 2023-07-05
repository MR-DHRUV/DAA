#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void dfsR(vector<vector<int>> &adjMatrix, vector<int> &dfs, unordered_map<int, bool> &visited, int start)
{
    if (visited[start] == false)
    {
        dfs.push_back(start);
        visited[start] = true;

        for (int i = 0; i < adjMatrix[start].size(); i++)
        {
            int neighbor = adjMatrix[start][i];
            if (visited[neighbor] == false)
            {
                dfsR(adjMatrix, dfs, visited, neighbor);
            }
        }
    }
}

vector<int> dfsOfGraph(int V, vector<vector<int>> &adjMatrix)
{
    unordered_map<int, bool> visited;
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        dfsR(adjMatrix, ans, visited, i);
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

    vector<int> ans = dfsOfGraph(V, adjMatrix);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
