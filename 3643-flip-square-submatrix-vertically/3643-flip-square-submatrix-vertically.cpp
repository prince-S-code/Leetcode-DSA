class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i=0;i<k/2;i++){
            for(int j=0;j<k;j++){
                int row=x+i;
                int col=y+j;
                int row_swap=x+k-1-i;
                swap(grid[row][col],grid[row_swap][col]);
            }
        }
        return grid;
    }
};