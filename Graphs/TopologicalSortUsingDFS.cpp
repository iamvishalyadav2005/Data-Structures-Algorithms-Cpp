class Solution {
  private:
    void dfs(int i,vector<vector<int>> &adj,vector<int> &visited,stack<int> &s){
        visited[i] = 1;
        
        for(int neigh : adj[i]){
            if(!visited[neigh]){
                dfs(neigh,adj,visited,s);
            }
        }
        s.push(i);
        return;
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        vector<int> visited(V,0);
        stack<int> s;
        vector<int> ans;
        
        for(int i = 0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,s);
            }
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};
