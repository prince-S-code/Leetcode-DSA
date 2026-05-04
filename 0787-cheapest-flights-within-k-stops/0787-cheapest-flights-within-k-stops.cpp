class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);// without declaring the size the code will result in the error while accessing adj[u]
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> q; // stops,node,distance
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
            auto current=q.front();
            q.pop();
            int stops=current.first;
            int node=current.second.first;
            int dis=current.second.second;
            if(stops > k){
                continue;
            }
            for(auto it:adj[node]){
                int nbr_node=it.first; 
                int weight=it.second;
                if(dis+weight < dist[nbr_node]){
                    dist[nbr_node]=dis+weight;
                    q.push({stops+1,{nbr_node,dis+weight}});
                }
            }
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};