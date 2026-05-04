class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<
        pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > pq;
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        vector<int> dr={0,0,-1,1};
        vector<int> dc={-1,1,0,0};
        while(!pq.empty()){
            auto current=pq.top();
            int effort=current.first;
            int row=current.second.first; 
            int col=current.second.second; 
            pq.pop();
            // optimization
            if(effort > dist[row][col]) continue;
            // case when the distination node is found
            if(row==m-1 && col==n-1) return effort;
            for(int i =0;i<4; i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                // checking the validity of the new row and the new col
                if(nr>=0 && nc>=0 && nr<m && nc<n){
                    // relaxing the edge
                    int new_effort=max(effort,abs(heights[row][col]-heights[nr][nc]));
                    if(new_effort < dist[nr][nc]){
                        dist[nr][nc]=new_effort;
                        pq.push({new_effort,{nr,nc}});
                    }

                }
            }
        }
        return 0;

    }
};