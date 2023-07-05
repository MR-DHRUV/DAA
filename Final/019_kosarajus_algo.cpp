#include <bits/stdc++.h>
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

// returns the no of scc
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // kosaraju's algorithm to determine the strongly connected components
    // Algo

    // call DFS and compute finishing time of each edge or simply compute topological sort of the graph
    // make transpose of the graph
    // now do the dfs concedering the nodes in the topological order

    vector<vector<int>> adj(v);
    vector<vector<int>> adjT(v);

    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);

        // creating transpose graph
        adjT[edge[1]].push_back(edge[0]);
    }

    // topo sort, isme cycle hoga tog dfs wala topo hi chalega kahn ni chal payga
    vector<int> topo = DFSTopo(v, adj);

    // dfs using topo ordering
    int count = 0;
    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++)
    {
        if (!visited[topo[i]])
        {
            count++; // we haev found 1 more scc
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