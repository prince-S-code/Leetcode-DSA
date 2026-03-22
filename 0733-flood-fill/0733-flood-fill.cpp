class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        queue<pair<int,int>> q;
        int m=image.size();
        int n=image[0].size();
        q.push({sr,sc});
        int orig_color=image[sr][sc];
        image[sr][sc]=color;
        vector<pair<int,int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
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
                    if(nx<m && nx>=0 && ny<n  && ny>=0 && image[nx][ny]==orig_color){
                        image[nx][ny]=color;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return image;
    }
};