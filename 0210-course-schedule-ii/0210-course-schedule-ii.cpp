class Solution {
    bool dfs(vector<vector<int>> adj, int node,vector<int>& visited, vector<int>& path_visited,vector<int>&ans){
        visited[node]=1;
        path_visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=1;
                path_visited[it]=1;
                if(dfs(adj,it,visited,path_visited,ans)){
                    return true;
                }
            }else if(path_visited[it]){
                return true;
            }
        }
        path_visited[node]=0;
        ans.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        int n=numCourses;
        vector<int> visited(n ,0);
        vector<int> path_visited(n ,0);
        vector<vector<int>> adj(n);
        for(auto elem:prerequisites){
            adj[elem[1]].push_back(elem[0]);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(adj,i,visited,path_visited,ans))
                    return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};