#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis) {
        vis[node] = 1;

        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, node, adj, vis))
                    return true;
            }
            else if (neighbor != parent) {
                return true;  // Cycle detected
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis))
                    return true;
            }
        }
        return false;
    }
};
