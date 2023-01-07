#include <list>
#include "Graph.h"
using namespace std;

Graph::Graph(const int vertices, bool direc) : n(vertices), e(0), direc(d)
{
    adjMatrix = new int[n][n];
}

Graph::~Graph()
{
    for (int i = 0; i < n; i++)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void Graph::doublSize()
{
}
void Graph::InsertVertex(int v)
{
    if (v > n - 1)
    {
        doublSize();
    }
}

void Graph::InsertEdge(int u, int v, int w)
{
    adjMatrix[u][v] = w;
    if (direc)
        adjMatrix[v][u] = w;
}
