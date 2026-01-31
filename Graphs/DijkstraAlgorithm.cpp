//Dijkstra’s Algorithm is used to find the shortest path from a single source vertex to all other vertices in a weighted graph.
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int src) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Skip outdated entries
        if (currDist > dist[node]) continue;

        for (auto it : adj[node]) {
            int adjNode = it[0];
            int weight = it[1];

            if (dist[node] + weight < dist[adjNode]) {
                dist[adjNode] = dist[node] + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

//Time & Space Complexity
//Time : O((V + E) log V)
//Space : O(V + E)
