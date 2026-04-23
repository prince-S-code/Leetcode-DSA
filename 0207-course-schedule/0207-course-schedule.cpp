class Solution {
    // dfs to detect whether there is cycle or not
    bool dfs(vector<vector<int>>& adj,int node,vector<int>& visited,vector<int>& path_visited){
        visited[node]=1;
        path_visited[node]=1;
        for(auto &u:adj[node]){
            if(!visited[u]){
                if(dfs(adj,u,visited,path_visited)){
                    return true;
                }
            }else if(path_visited[u]){
                return true;
            }
        }
        path_visited[node]=0;
        return false;
    }


public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // using dfs
        // making the adjacency matrix
        int n=numCourses;
        vector<vector<int>> adj(n);
        for(auto& it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n,0);
        vector<int> path_visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(adj,i,visited,path_visited)){
                    return false;
                }
            }
        }
        return true;
    }
};