class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        // pushing the rotten indexes to the queue and counting the fresh ones
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int minutes=0;
        vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty() && fresh>0){
            int size=q.size();
            minutes++;
            for(int i=0;i<size;i++){
                auto current=q.front();
                q.pop();
                int x=current.first;
                int y=current.second;
                for(auto direction:directions){
                    int nx=x+direction.first;
                    int ny=y+direction.second;
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        fresh--;
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return fresh==0?minutes:-1;
    }
};