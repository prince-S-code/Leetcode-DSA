class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    island++;
                    grid[i][j] = '0';
                    while (!q.empty()) {
                        auto current = q.front();
                        int x = current.first;
                        int y = current.second;
                        q.pop();
                        for (auto direction : directions) {
                            int nx = x + direction.first;
                            int ny = y + direction.second;
                            if (nx < m && nx >= 0 && ny < n && ny >= 0 &&
                                grid[nx][ny] == '1') {
                                grid[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return island;
    }
};