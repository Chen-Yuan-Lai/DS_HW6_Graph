#include "Graph.h"
#include <vector>
#include <iostream>
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
    capacity *= 2;
}
void MinPQ::push(const Node &x)
{ // Insert x into the min heap
    if (heapSize == capacity)
    {
        doubleSize();
    }
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
    adjMatrix = new int *[capacity];
    for (int i = 0; i < capacity; i++)
    {
        adjMatrix[i] = new int[capacity];
        fill(adjMatrix[i], adjMatrix[i] + capacity, 0);
    }
}

Graph::~Graph()
{
    for (int i = 0; i < capacity; i++)
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
    if (!direc)
        adjMatrix[v][u] = w;
    e++;
}

void Graph::MinSpanTree()
{
    int totalCost = 0;
    vector<int> T;
    cout << n << endl;
    cout << e << endl;

    // add edges from adjMatrix into MaxPQ
    MinPQ E;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (adjMatrix[i][j] > 0)
            {
                E.push(Node(i, j, adjMatrix[i][j]));
            }
        }
    }
    // Kruskal's algorithm
    while (((int)T.size() < n) && (!E.IsEmpty()))
    {
        pair<bool, bool> intersect(false, false);
        Node lowestE = E.top();
        E.pop();

        // check vertecies in T not intersect with lowestE
        if (!T.empty())
        {
            // search v1
            for (auto &t : T)
            {
                if (lowestE.v1 == t)
                {
                    intersect.first = true;
                    break;
                }
            }

            // search v2
            for (auto &t : T)
            {
                if (lowestE.v2 == t)
                {
                    intersect.second = true;
                    break;
                }
            }
        }
        // insert unique vertex in to graph
        if (!intersect.first || !intersect.second)
        {
            if (!intersect.first && !intersect.second)
            {
                T.push_back(lowestE.v1);
                T.push_back(lowestE.v2);
            }
            else if (!intersect.first)
            {
                T.push_back(lowestE.v1);
            }
            else
            {
                T.push_back(lowestE.v2);
            }
            totalCost += lowestE.weight;
        }
    }
    if ((int)T.size() < n - 1)
    {
        cout << "no spanning tree" << endl;
    }
    else
    { // print the tree and total cost
        cout << "Minimal cost spanning tree:" << endl;
        for (int i = 0; i < (int)T.size() - 1; i++)
        {
            cout << T[i] << " " << T[i + 1] << endl;
        }
        cout << "total cost: " << totalCost << endl;
    }
}

void Graph::ShortestPath(int v)
{
    int dist[n];
    bool s[n];
    for (int i = 0; i < n; i++)
    { // initialize
        if (adjMatrix[v][i] == 0)
        {
            dist[i] = 999;
        }
        else
        {
            dist = adjMatrix[v][i];
        }
        s[i] = false;
    }
    dist[v] = 0;
    s[v] = true;

    //  choose a value u such that:
    //  dist[u] = minimum dist[w], where s[w] = false
    int u;
    for (int i = 0; i < n; i++)
    {
        if (!s[i])
        {
            u = i;
        }
    }
}
