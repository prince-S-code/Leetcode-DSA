class Solution {
    void rotate_90(vector<vector<int>>& mat){
        int n=mat.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int col=0;col<n/2;col++){
            for(int row=0;row<n;row++){
                swap(mat[row][col],mat[row][n-1-col]);
            }
        }
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool same=false;
        int n=mat.size();
        for(int i=0;i<5;i++){
            if(same){
                return true;
            }
            rotate_90(mat);
            bool flag=true;
            for(int i=0;i<n;i++){
                if(flag==false)
                    break;
                for(int j=0;j<n;j++){
                    if(target[i][j]!=mat[i][j]){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag) same=true;
        }
        return false;
    }
};