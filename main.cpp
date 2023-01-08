#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    Node a(1, 0, 20);
    Node b(0, 2, 15);
    Node c(1, 5, 30);
    Node d(2, 3, 4);
    Node e(2, 5, 10);
    Node f(5, 3, 4);
    Node g(5, 4, 10);
    Node h(4, 3, 15);
    Node i(4, 1, 10);
    Node edge[] = {a, b, c, d, e, f, g, h, i};
    MinPQ x;

    for (int i = 0; i < 9; i++)
    {
        x.push(edge[i]);
    }

    while (!x.IsEmpty())
    {
        cout << x.top().weight << endl;
        x.pop();
    }
}