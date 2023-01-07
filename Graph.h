#ifndef GRAPH_H
#define GRAPH_H
#include <list>
using namespace std;

class Graph
{
public:
    Graph(const int vertices = 10, bool d = false);
    ~Graph();
    void InsertEdge(int u, int v, int w);
    void InsertVertex(int v);
    void doublSize();

private:
    int **adjMatrix;
    int n, e;
    bool direc;
}
#endif