class Solution {
    bool isvalid(vector<vector<char>>& board, int row, int col, int index,
                 vector<vector<char>>& visited, string& word) {

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return false;

        if (board[row][col] == word[index] && visited[row][col] == '.')
            return true;

        return false;
    }

    bool solve(vector<vector<char>>& board, int row, int col, int index,
               vector<vector<char>>& visited, string& word) {

        if (index == word.size())
            return true;

        bool found = false;

        if (isvalid(board, row, col - 1, index, visited, word)) {
            visited[row][col-1] = '1';
            found = solve(board,row,col-1,index+1,visited,word);
            visited[row][col-1] = '.';
        }

        if (!found && isvalid(board, row, col + 1, index, visited, word)) {
            visited[row][col+1] = '1';
            found = solve(board,row,col+1,index+1,visited,word);
            visited[row][col+1] = '.';
        }

        if (!found && isvalid(board, row-1, col, index, visited, word)) {
            visited[row-1][col] = '1';
            found = solve(board,row-1,col,index+1,visited,word);
            visited[row-1][col] = '.';
        }

        if (!found && isvalid(board, row+1, col, index, visited, word)) {
            visited[row+1][col] = '1';
            found = solve(board,row+1,col,index+1,visited,word);
            visited[row+1][col] = '.';
        }

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<char>> visited(n, vector<char>(m,'.'));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(board[i][j]==word[0]){
                    visited[i][j]='1';

                    if(solve(board,i,j,1,visited,word))
                        return true;

                    visited[i][j]='.';
                }
            }
        }

        return false;
    }
};