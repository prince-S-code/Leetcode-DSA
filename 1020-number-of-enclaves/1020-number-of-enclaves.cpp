class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // ones is the no of probable ones which donot lead to boundary
        int ones=0;
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(i==0 || j==0 || i==m-1 || j==n-1){ // boundary locations
                        q.push({i,j});
                    }else{
                        ones++;
                    }
                }
            }
        }
        // vector<vector<bool>>visited(m,vector<bool>(n,false));
        vector<pair<int,int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto current=q.front();
            q.pop();
            int x=current.first; 
            int y=current.second;
            // visited[x][y]=true;
            for(auto direction : directions){
                int nx=x+direction.first;
                int ny=y+direction.second;
                if(nx<m-1 && nx>0 && ny>0 && ny<n-1 && grid[nx][ny]==1){
                    ones--;
                    q.push({nx,ny});
                    grid[nx][ny]=0;
                }
            }
        }
        return ones;
    }
};