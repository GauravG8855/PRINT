#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

int main() {
    int V, E, source;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (src dest weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    cout << "Enter the source vertex: ";
    cin >> source;

    const int INF = 1e9;
    vector<int> dist(V, INF);
    dist[source] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (auto &edge : edges) {
            if (dist[edge.src] != INF && dist[edge.src] + edge.weight < dist[edge.dest]) {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    bool hasNegativeCycle = false;
    for (auto &edge : edges) {
        if (dist[edge.src] != INF && dist[edge.src] + edge.weight < dist[edge.dest]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "\nGraph contains a negative weight cycle!" << endl;
    } else {
        cout << "\nShortest distances from source vertex " << source << ":\n";
        for (int i = 0; i < V; i++) {
            if (dist[i] == INF)
                cout << i << " : INF" << endl;
            else
                cout << i << " : " << dist[i] << endl;
        }
    }

    cout << "\nTime complexity verification:" << endl;
    cout << "Outer loop runs (V - 1) times = " << (V - 1) << endl;
    cout << "Inner loop runs E times per iteration = " << E << endl;
    cout << "Total operations ≈ (V - 1) * E = " << (V - 1) * E << " ⇒ O(V * E)" << endl;

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// // Structure to represent a graph edge
// struct Edge {
//     int src, dest, weight;
// };

// int main() {
//     int V, E, source;
//     cout << "Enter number of vertices: ";
//     cin >> V;
//     cout << "Enter number of edges: ";
//     cin >> E;

//     vector<Edge> edges(E);
//     cout << "Enter edges (src dest weight):\n";
//     for (int i = 0; i < E; i++) {
//         cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
//     }

//     cout << "Enter the source vertex: ";
//     cin >> source;

//     const int INF = 1e9;
//     vector<vector<int>> dp(V, vector<int>(V, INF)); // dp[i][v] = shortest distance to v using ≤ i edges
//     dp[0][source] = 0;

//     // Build DP table iteratively
//     for (int i = 1; i < V; i++) {
//         dp[i] = dp[i - 1]; // Start with previous distances
//         for (auto &edge : edges) {
//             if (dp[i - 1][edge.src] != INF && dp[i - 1][edge.src] + edge.weight < dp[i][edge.dest]) {
//                 dp[i][edge.dest] = dp[i - 1][edge.src] + edge.weight;
//             }
//         }

//         // Print DP table after each iteration
//         cout << "\nAfter iteration " << i << " (using at most " << i << " edges):\n";
//         for (int v = 0; v < V; v++) {
//             if (dp[i][v] == INF)
//                 cout << "Vertex " << v << " : INF\n";
//             else
//                 cout << "Vertex " << v << " : " << dp[i][v] << "\n";
//         }
//     }

//     // Final result after (V-1) relaxations
//     cout << "\nFinal shortest distances from source vertex " << source << ":\n";
//     for (int v = 0; v < V; v++) {
//         if (dp[V - 1][v] == INF)
//             cout << v << " : INF\n";
//         else
//             cout << v << " : " << dp[V - 1][v] << "\n";
//     }

//     // Negative cycle detection
//     bool hasNegativeCycle = false;
//     vector<int> dist = dp[V - 1];
//     for (auto &edge : edges) {
//         if (dist[edge.src] != INF && dist[edge.src] + edge.weight < dist[edge.dest]) {
//             hasNegativeCycle = true;
//             break;
//         }
//     }

//     if (hasNegativeCycle)
//         cout << "\nGraph contains a negative weight cycle!\n";
//     else
//         cout << "\nNo negative weight cycle detected.\n";

//     // Time complexity explanation
//     cout << "\nTime Complexity Verification:\n";
//     cout << "Outer loop runs (V - 1) times = " << (V - 1) << "\n";
//     cout << "Inner loop runs E times per iteration = " << E << "\n";
//     cout << "Total operations ≈ (V - 1) * E = " << (V - 1) * E << " ⇒ O(V * E)\n";

//     return 0;
// }
