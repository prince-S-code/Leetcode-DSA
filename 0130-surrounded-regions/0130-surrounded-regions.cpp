class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>> q; 
        // pushing all the safe cells in the queue
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') q.push({i,0});
            if(board[i][n-1]=='O') q.push({i,n-1});
        }
        for(int i=1;i<n-1;i++){
            if(board[0][i]=='O') q.push({0,i});
            if(board[m-1][i]=='O') q.push({m-1,i});
        }

        vector<pair<int ,int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto current=q.front();
                q.pop();
                int x=current.first;
                int y=current.second;
                board[x][y]='#';
                for(auto direction:directions){
                    int nx=x+direction.first;
                    int ny=y+direction.second;
                    if(nx<m-1 && nx>0 && ny<n-1 && ny>0 && board[nx][ny]=='O'){
                        q.push({nx,ny});
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};