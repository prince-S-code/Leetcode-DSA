class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        // pushing the rotten indexes to the queue for the points to act as the source and counting the no of fresh ones
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1){
                    fresh++;
                }else if(grid[row][col]==2){
                    q.push({row,col});
                }
            }
        }

        // multisource bfs
        int time=0;
        vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty() && fresh>0){
            int size=q.size();
            time++;
            for(int i=0;i<size;i++){
                auto current=q.front();
                q.pop();
                int row=current.first;
                int col=current.second;
                for(auto direction:directions){
                    int new_row=row+direction.first;   
                    int new_col=col+direction.second;
                    if(new_row < m && new_row >=0 && new_col<n && new_col>=0 && grid[new_row][new_col]==1){
                        grid[new_row][new_col]=2;
                        fresh--;
                        q.push({new_row,new_col});
                    }
                }
            }
        }
        return fresh==0?time:-1;
    }
};