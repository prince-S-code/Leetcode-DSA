class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>> q; 
        vector<vector<int>> dis(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }

        vector<pair<int ,int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto current=q.front();
                q.pop();
                int x=current.first;
                int y=current.second;
                for(auto direction:directions){
                    int nx=x+direction.first;
                    int ny=y+direction.second;
                    if(nx<m && nx>=0 && ny<n && ny>=0 && dis[nx][ny]==-1){
                        q.push({nx,ny});
                        dis[nx][ny]=dis[x][y]+1;
                    }
                }
            }
        }
        return dis;
    }
};