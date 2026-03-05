class Solution {
    bool issafe(vector<string>&board,int row,int col){
        // checkign row
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        // checkign col
        for(int i=0;i<col;i++){
            if(board[row][i]=='Q'){
                return false;
            }
        }
        // primary diagonal
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        // secondary diagonal
        for(int i=row-1,j=col+1;i>=0 && j<board.size();i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string>& board,int row,int n,vector<vector<string>>& ans){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(issafe(board,row,col)){
                board[row][col]='Q';
                solve(board,row+1,n,ans);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(board,0,n,ans);
        return ans;
    }
};