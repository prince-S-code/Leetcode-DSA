class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // using bfs
        // vector<int> visited(n,0);
        // there is no need for visited array the color array will have the uncolored nodes which tells about visited and unvisited
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){// for loop is for the unconnected graph has it been connected graph there would have been no need of this for loop
            if(color[i]==-1){ // that is the node is uncolored and unvisited
                queue<int> q;
                q.push(i); 
                color[i]=1;//initialising it with any random color, 0 would have also worked
                while(!q.empty()){
                    int size=q.size();// to know how many nodes to process in the single cycle
                    for(int i=0;i<size;i++){
                        int node=q.front();
                        q.pop();
                        for(int & u:graph[node]){
                            if(color[u]==-1){
                                color[u]=1^color[node];
                                q.push(u);
                            }else if(color[u]==color[node]){
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