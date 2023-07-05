#include <bits/stdc++.h>
using namespace std;

class Solution
{

    void dfsR(vector<int> adj[], vector<int> &dfs, unordered_map<int, bool> &visited, int start)
    {
        if (visited[start] == false)
        {
            dfs.push_back(start);
            visited[start] = true;

            for (int i = 0; i < adj[start].size(); i++)
            {
                if (visited[adj[start][i]] == false)
                {
                    dfsR(adj, dfs, visited, adj[start][i]);
                }
            }
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // keep following a path until we have reach a vertex at which there are no unvisited connected nodes, when we are at such a vertex we backtrack to last visited vertex using a stack.

        unordered_map<int, bool> visited;
        vector<int> ans;

        int start = 0;

        for (int i = 0; i < V; i++)
        {
            dfsR(adj, ans, visited, i);
        }

        return ans;
    }

    vector<int> dfsOfGraphIter(int V, vector<int> adj[])
    {
        stack<int> st;
        unordered_map<int, bool> visited;
        vector<int> ans;

        int start = 0;

        while (start != -1 || !st.empty())
        {
            if (start != -1)
            {
                if (visited[start] == false)
                {
                    ans.push_back(start);
                    visited[start] = true;
                }

                bool areUnvisited = false;

                for (int i = 0; i < adj[start].size(); i++)
                {
                    if (visited[adj[start][i]] == false)
                    {
                        areUnvisited = true;
                        st.push(start);
                        start = adj[start][i];
                        break;
                    }
                }

                // there is no unvisited adjacent node
                if (areUnvisited == false)
                {
                    start = -1;
                }
            }
            else
            {
                start = st.top();
                st.pop();
            }
        }

        return ans;
    }
};

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
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
