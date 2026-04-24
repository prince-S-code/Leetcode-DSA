class Solution {
    // dfs algorithm for cycle detection
    // return true if cycle found else return false;
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& visited){
        if(visited[node]==1) return true;
        if(visited[node]==2) return false;
        visited[node]=1;// currently in recursion stack
        for(auto nbr:graph[node]){
                if(dfs(nbr,graph,visited)){
                    return true;
                }
        }
        visited[node]=2; // 2 is marked for the safe state
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // using dfs
        int n=graph.size();
        vector<int> visited(n,0);
        vector<int> safe;
        for(int i=0;i<n;i++){
            // if(!visited[i]){
                if(!dfs(i,graph,visited)){
                    safe.push_back(i);
                }
            // }
        }
        return safe;
    }
};