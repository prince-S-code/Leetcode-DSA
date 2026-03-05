class Solution {
    bool issafe(vector<vector<char>>& board, int row, int col, char val) {
        // check row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val) {
                return false;
            }
        }
        // check col
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == val) {
                return false;
            }
        }

        // check 3*3 board
        int r = (row / 3) * 3;
        int c = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[r + i][c + j] == val) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int row,int col) {
        int nextrow = row;
        int next_col = col + 1;
        if (row == 9) {
            return true;
        }
        if (next_col == 9) {
            next_col = 0;
            nextrow = row + 1;
        }
        if(board[row][col]!='.'){
            return solve(board,nextrow,next_col);
        }
        for (int val = 1; val <= 9; val++) {
            if(issafe(board,row,col,'0'+val)){
                board[row][col] = '0'+val;
                if(solve(board, nextrow, next_col)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};