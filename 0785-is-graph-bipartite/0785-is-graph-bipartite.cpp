class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){//uncolored
                queue<int> q;
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int size=q.size();
                    for(int i=0;i<size;i++){
                        int node=q.front();
                        q.pop();
                        for(int neighbour:graph[node]){
                            if(color[neighbour]==-1){
                                q.push(neighbour);
                                color[neighbour]=1^color[node];
                            }else if(color[neighbour]==color[node]){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};