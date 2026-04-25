class Solution {
public: 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        vector<vector<int>> visited(n,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q; //storing the locations and the steps
        q.push({{0,0},1});
        visited[0][0]=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto current=q.front();
                q.pop();
                int row=current.first.first;
                int col=current.first.second;
                int steps=current.second;
                if(row==n-1 && col==n-1){
                    return steps;
                }
                vector<int> dr={0,0,-1,-1,-1,+1,+1,+1};
                vector<int> dc={-1,+1,-1,0,+1,-1,0,+1};
                for(int gap=0;gap<8;gap++){
                    int nr=row+dr[gap];
                    int nc=col+dc[gap];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc] && grid[nr][nc]==0){
                        q.push({{nr,nc},steps+1});
                        visited[nr][nc]=1;
                    }
                }
            }
        }
        return -1;
    }
};