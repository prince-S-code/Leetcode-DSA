class Solution {
    void dfs(vector<vector<char>>& grid,int row,int col,int& m,int& n){
        grid[row][col]='0';//marking the node as visited or converting it into water
        vector<int>dr={0,0,1,-1};
        vector<int>dc={1,-1,0,0};
        for(int i=0;i<4;i++){
            int new_row=row+dr[i];
            int new_col=col+dc[i];
            if(new_row<m && new_row>=0 && new_col>=0 && new_col<n && grid[new_row][new_col]=='1'){
                dfs(grid,new_row,new_col,m,n);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};