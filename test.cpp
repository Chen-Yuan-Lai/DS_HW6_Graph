

// void MatrixWDigraph::ShortestPath(const int n, const int v)
// { // dist[j], 0<= j < n, is set to the length of the shortest path from v to j
//   // in a digraph G with n vertices and edge lengths given by length[i][j].
//   // path[j], 0 <= j < n, is a queue array that store nodes in sortest path
//   // from v to j.
//     for (int i = 0; i < n; i++)
//     { // initialize
//         dist[i] = length[v][i];
//     }
//     s[v] = true;
//     dist[v] = 0;

//     for (int i = 0; i < n - 2; i++)
//     { // determine n-1 paths from vertex v
//       //  choose returns a value u such that:
//       //  dist[u] = minimum dist[w], where s[w] = false
//         int u Choose(n);
//         s[u] = true;
//         for (int w = 0; i < n; w++)
//         {
//             if (!s[w] && dist[u] + length[u][w] < dist[w])
//             {
//                 dist[w] = dist[u] + length[u][w];
//                 // put that u into the queue
//                 // where store the shotest path from v to w
//                 path[w].push(u);
//             }
//         }
//     }
// }