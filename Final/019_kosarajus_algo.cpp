#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

void dfsR(vector<vector<int>> &adj, stack<int> &st, unordered_map<int, bool> &visited, int v)
{
    if (visited[v] == false)
    {
        visited[v] = true;
        for (int i = 0; i < adj[v].size(); i++)
        {
            if (visited[adj[v][i]] == false)
            {
                dfsR(adj, st, visited, adj[v][i]);
            }
        }
        st.push(v);
    }
}

vector<int> DFSTopo(int V, vector<vector<int>> &adj)
{
    unordered_map<int, bool> visited;
    vector<int> ans;
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        dfsR(adj, st, visited, i);
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

void DFS(int v, vector<bool> &visited, vector<vector<int>> &adj)
{
    if (!visited[v])
    {
        visited[v] = true;

        for (auto i : adj[v])
        {
            if (!visited[i])
            {
                DFS(i, visited, adj);
            }
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(v);
    vector<vector<int>> adjT(v);

    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adjT[edge[1]].push_back(edge[0]);
    }

    vector<int> topo = DFSTopo(v, adj);

    int count = 0;
    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++)
    {
        if (!visited[topo[i]])
        {
            count++;
            DFS(topo[i], visited, adjT);
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> edges = {{0, 1},
                                 {1, 2},
                                 {1, 4},
                                 {2, 3},
                                 {3, 2}};
    cout << stronglyConnectedComponents(5, edges);

    return 0;
}
