#include <iostream>
#include "Graph.h"
// #include "Graph.cpp"
using namespace std;

int main()
{
    // insert vertecies
    Graph g(6);
    for (int i = 0; i < 6; i++)
    {
        g.InsertVertex(i);
    }
    // insert edge
    g.InsertEdge(0, 1, 20);
    g.InsertEdge(0, 2, 15);
    g.InsertEdge(1, 4, 10);
    g.InsertEdge(1, 5, 30);
    g.InsertEdge(2, 3, 4);
    g.InsertEdge(2, 5, 10);
    g.InsertEdge(3, 4, 15);
    g.InsertEdge(3, 5, 4);
    g.InsertEdge(4, 5, 10);

    g.MinSpanTree();

    return 0;
}