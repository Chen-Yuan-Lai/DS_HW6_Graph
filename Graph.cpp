#include "Graph.h"
using namespace std;

MinPQ::MinPQ(int theCapcity) : heapSize(0), capacity(theCapcity)
{
    heap = new Node[capacity + 1]; // heap[0] is not used
}
MinPQ::~MinPQ()
{
    delete heap;
}

void MinPQ::doubleSize()
{
    Node *tmp = new Node[(2 * capacity) + 1];
    copy(heap, heap + capacity + 1, tmp);
    delete[] heap;
    tmp = heap;
}
void MinPQ::push(const Node &x)
{ // Insert x into the min heap
    if (heapSize == capacity)
    {
        doubleSize();
    }
    capacity *= 2;

    int currentNode = ++heapSize;
    while (currentNode != 1 && heap[currentNode / 2].weight > x.weight)
    {                                              // buble up
        heap[currentNode] = heap[currentNode / 2]; // move parent down
        currentNode /= 2;
    }
    heap[currentNode] = x;
}

void MinPQ::pop()
{ // delete min element
    if (IsEmpty())
        throw "Heap is empty. Cannot delete.";
    // remove last element
    Node lastE = heap[heapSize--];

    // trickle down
    int currentNode = 1; // root
    int child = 2;       // a child of currentNode
    while (child <= heapSize)
    {
        // set child to larger child of currentNode
        if (child < heapSize && heap[child].weight > heap[child + 1].weight)
            child++;

        // can we put lastE in currentNode?
        if (lastE.weight <= heap[child].weight) // yes
            break;

        // No
        heap[currentNode] = heap[child]; // move child up
        currentNode = child;
        child *= 2; // move down a level
    }
    heap[currentNode] = lastE;
}

Graph::Graph(int vertices, bool d) : n(0), e(0), direc(d), capacity(vertices)
{
    adjMatrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        adjMatrix[i] = new int[n];
    }
}

Graph::~Graph()
{
    for (int i = 0; i < n; i++)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void Graph::InsertVertex(int v)
{
    if (v > capacity)
        throw "vertex is out of the graph";
    if (v < n)
        throw "vertex is duplicate";
    n++;
}

void Graph::InsertEdge(int u, int v, int w)
{
    if (u >= n || v >= n)
        throw "the graph has no these vertex";
    adjMatrix[u][v] = w;
    if (direc)
        adjMatrix[v][u] = w;
}
