bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Step 1: Create adjacency listfor the Courses
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for(auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        // Step 2: Push all nodes wi th indegree 0 into queue
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        
        // Step 3: BFS Traversal
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            for(auto neighbor : adj[node]) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Step 4: Check if all courses processed
        return count == numCourses;
    }
