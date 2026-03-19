class Solution {
    bool issafe(int row,int col,vector<string>& board){
        int n=board.size();
        // row check
        for(int i=0;i<col;i++){
            if(board[row][i]=='Q'){
                return false;
            }
        }
        // column check
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        // primary diagonal check
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        // secondary diagonal check
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }

    void solve(vector<string>& board,int row,vector<vector<string>>& ans){
        int n=board.size();
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(issafe(row,col,board)){
                board[row][col]='Q';
                solve(board,row+1,ans);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(board,0,ans);
        return ans;
    }
};