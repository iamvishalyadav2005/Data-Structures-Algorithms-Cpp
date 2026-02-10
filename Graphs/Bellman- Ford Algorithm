

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    // Step 1: Relax edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Step 2: Detect negative weight cycle
    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int wt = e[2];

        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return {-1}; // Negative cycle detected
        }
    }

    return dist;
}

//Time Complexity	O(V × E)
//Space Complexity	O(V)
