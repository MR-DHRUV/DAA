#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // BFS
        // simmilar to level-order-traversal
        // in each iteration we print/traverse all the edges that are at a unit distance from a source node, then each of these node becomes source node and so on ... like level order traversal

        // Algo
        // we need a queue and a visited map to keep a track of visited vertices

        // here adj[i] contains verices connected to ith vertex
        // O(V+E)

        // algo is same for directed and undirected graph as pnly adjacency matrix will change

        queue<int> qt;
        unordered_map<int, bool> visited;
        vector<int> ans;

        // as given we have to traverse from left to right
        // starting from 0
        qt.push(0);
        visited[0] = true;
        ans.push_back(0);

        while (!qt.empty())
        {
            int t = qt.front();
            qt.pop();

            for (int i = 0; i < adj[t].size(); i++)
            {
                if (visited[adj[t][i]] == false)
                {
                    ans.push_back(adj[t][i]);
                    visited[adj[t][i]] = true;
                    qt.push(adj[t][i]);
                }
            }

            // optimization
            // if we have traversed all the vertices and only some edges are left, there is no need to traverse them
            if (ans.size() == V)
            {
                break;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
