class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // using bfs
        int n=numCourses;
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for(auto &it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        int count=0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto & u:adj[node]){
                indegree[u]--;
                if(indegree[u]==0){
                    q.push(u);
                }
            }
        }
        if(count!=n) return false;
        return true;
    }
};