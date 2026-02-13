class Solution {
    

  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> toposort;
        vector<vector<int>> adj(V);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
      vector<int> indegree(V);
      //Calculate the Indegree of Each Vertices
      for(int i = 0;i<V;i++){
          for(int it : adj[i]){
              indegree[it]++;
          }
      }
      //Create a queue and push all the vertices having indegree zero
      queue<int> q;
      for(int i = 0;i<V;i++){
          if(indegree[i]==0){
              q.push(i);
              toposort.push_back(i);
          }
      }
      while(!q.empty()){
          int node = q.front();
          q.pop();
          for(int neigh : adj[node]){
              indegree[neigh]--;
              if(indegree[neigh]==0){
                  q.push(neigh);
                  toposort.push_back(neigh);
              }
          }
      }
      
      return toposort;
    }
};
