#ifndef GRAPH_H
#define GRAPH_H
#include <list>
using namespace std;

class Node
{
    friend class MinPQ;

public:
    Node(int v = 0, int u = 0, int w = 0) : v1(v), v2(u), weight(w){};
    int v1;
    int v2;
    int weight;
};

class MinPQ
{
public:
    MinPQ(int theCapcity = 10);
    ~MinPQ();
    void push(const Node &x);
    void pop();
    Node &top() const { return heap[1]; }
    void doubleSize();
    bool IsEmpty() const { return heapSize == 0; }

private:
    Node *heap;
    int heapSize;
    int capacity;
};

class Graph
{
public:
    Graph(int vertices = 10, bool d = false);
    ~Graph();
    void InsertEdge(int u, int v, int w);
    void InsertVertex(int v);
    void MinSpanTree();
    void ShortestPath(int v);
    int **getAdjMatrix() const { return adjMatrix; }

private:
    int n, e;
    bool direc;
    int capacity;
    int **adjMatrix;
};
#endif