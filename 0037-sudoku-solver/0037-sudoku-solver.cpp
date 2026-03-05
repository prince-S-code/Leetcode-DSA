class Solution {
    bool issafe(vector<vector<char>>& board, int row, int col,char val){
        // checking row
        for(int i=0;i<9;i++){
            if(board[row][i]==val){
                return false;
            }
        }

        // checking columns
        for(int i=0;i<9;i++){
            if(board[i][col]==val){
                return false;
            }
        }

        // checking 3 cross 3 grid
        int row_base=3*(row/3);
        int col_base=3*(col/3);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[row_base+i][col_base+j]==val){
                    return false;
                }
            }
        }
        return true; // in case all the condition checks are true;
    }

    bool solve(vector<vector<char>>& board,int row,int col){
        // base cases and modification of row and column indexes 
        if(row==9){
            return true;
        }
        int next_row=row;
        int next_col=col+1;

        if(next_col==9){
            next_col=0;
            next_row=row+1;
        }

        // the case when the element is already filled one
        if(board[row][col]!='.'){
            return solve(board,next_row,next_col);
        }
        
        // now the case when there is an empty space
        // tryin out all the possible values
        for(int i=1;i<=9;i++){
            char val='0'+i;
            if(issafe(board,row,col,val)){
                board[row][col]=val;
                // i have done it without if returning the value of solve for next row and next col which is wrong
                if(solve(board,next_row,next_col)){
                    return true;
                }
                board[row][col]='.'; // backtracking
                // return solve(board,next_row,next_col);
                // the above return statement is wrong because the function wont check again for the other values and there will be no backtracking
            }
        }
        return false;
    }


public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};