class Solution {
    void dfs_helper(int node,vector<vector<int>>& adj,vector<bool>& visited){
        visited[node]=true;
        for(int neighbour:adj[node]){
            if(!visited[neighbour]){
                dfs_helper(neighbour,adj,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j])
                    adj[i].push_back(j);
                // adj[j].push_back(i);
            }
        }

        // running the dfs loop
        int ans=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs_helper(i,adj,visited);
            }
        }
        return ans;
    }
};