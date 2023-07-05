#include <iostream>
#include <vector>

using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adjMatrix;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void printVertexCover();
};

Graph::Graph(int V)
{
    this->V = V;
    adjMatrix.resize(V, vector<int>(V, 0));
}

void Graph::addEdge(int v, int w)
{
    adjMatrix[v][w] = 1;
    adjMatrix[w][v] = 1;
}

void Graph::printVertexCover()
{
    vector<bool> visited(V, false);

    for (int u = 0; u < V; u++)
    {
        if (!visited[u])
        {
            for (int v = 0; v < V; v++)
            {
                if (adjMatrix[u][v] && !visited[v])
                {
                    visited[u] = true;
                    visited[v] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (visited[i])
        {
            cout << i << " ";
        }
    }
}

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.printVertexCover();

    return 0;
}
