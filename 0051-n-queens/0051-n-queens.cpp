class Solution {
    bool issafe(vector<string>& grid, int row, int col, int n){
        // checking row
        for(int i=0;i<col;i++){
            if(grid[row][i]=='Q'){
                return false;
            }
        }
        // checking colums
        for(int i=0;i<row;i++){
            if(grid[i][col]=='Q'){
                return false;
            }
        }
        // checking primary diagonal upper
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(grid[i][j]=='Q'){
                return false;
            }
        }
        // checking secondary diagonal upper
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(grid[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }

    void solve(vector<string>& grid, int row, int col, int n,vector<vector<string>>& ans){
        if(row==n){
            ans.push_back(grid);
            return;
        }
        for(int col=0;col<n;col++){
            if(issafe(grid,row,col,n)){
                grid[row][col]='Q';
                solve(grid,row+1,col,n,ans);
                grid[row][col]='.';
            }
        }
        // return ans;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n,string(n,'.'));// initialise the grid 
        vector<vector<string>> ans;
        solve(grid,0,0,n,ans);
        return ans;
        
    }
};