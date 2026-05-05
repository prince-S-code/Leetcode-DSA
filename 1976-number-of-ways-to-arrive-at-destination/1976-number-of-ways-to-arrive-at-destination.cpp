class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;  

        pq.push({0,0});

        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();

            if(dis > dist[node]) continue;

            for(auto &nbr : adj[node]){
                int next = nbr.first;
                int weight = nbr.second;

                long long newDist = dis + weight;

                if(newDist < dist[next]){
                    dist[next] = newDist;
                    ways[next] = ways[node];
                    pq.push({newDist, next});
                }
                else if(newDist == dist[next]){
                    ways[next] = (ways[next] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};