class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> safe;
        vector<int> outdegree(n,0);
        vector<vector<int>> revgraph(n);
        // building reverse graph and outdegree
        for(int i=0;i<n;i++){
            outdegree[i]=graph[i].size();
            for(int neighbour:graph[i]){
                revgraph[neighbour].push_back(i);
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int current=q.front();
            safe.push_back(current);
            q.pop();
            for(auto nbr:revgraph[current]){
                outdegree[nbr]--;
                // safe.push_back(currrent);
                if(outdegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};