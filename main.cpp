#include <iostream>
#include "Graph.h"
// #include "Graph.cpp"
using namespace std;

int main()
{
    while (1)
    {
        cout << "\n"
             << "================================\n"
             << "What graph do you input: \n"
             << "(1) directed graph\n"
             << "(2) un-directed graph\n"
             << "(3) exit\n"
             << endl;

        char option;
        cin >> option;
        if (option == '3')
        {
            cout << "Exit the program!" << endl;
            break;
        }

        int vertcies;
        int edges;
        cout << "Vertex number: ";
        cin >> vertcies;
        cout << "Edge number: ";
        cin >> edges;
        int v;
        int u;
        int w;
        if (option == '1')
        {
            Graph g(vertcies, true);
            // insert vertecies
            for (int i = 0; i < vertcies; i++)
            {
                g.InsertVertex(i);
            }
            for (int i = 0; i < edges; i++)
            {
                cout << "Enter a edge[vertex1 vertext2 weight]: ";
                cin >> v >> u >> w;
                g.InsertEdge(v, u, w);
            }
            int source;
            cout << "Source vertex: ";
            cin >> source;
            g.ShortestPath(source);
        }
        else if (option == '2')
        {
            Graph g(vertcies);
            // insert vertecies
            for (int i = 0; i < vertcies; i++)
            {
                g.InsertVertex(i);
            }
            for (int i = 0; i < edges; i++)
            {
                cout << "Enter a edge[vertex1, vertext2, weight]: ";
                cin >> v >> u >> w;
                g.InsertEdge(v, u, w);
            }
            g.MinSpanTree();
        }
    }
}