#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        // dist[i][j] stores the minimum effort required to reach cell (i, j)
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        
        // Min-heap: {effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        int dr[] = {0, 0, -1, 1};
        int dc[] = {1, -1, 0, 0};
        
        while (!pq.empty()) {
            int effort = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            // If we reached the destination, this is our minimum effort
            if (r == m - 1 && c == n - 1) return effort;
            
            // Optimization: skip if we've already found a better path to this cell
            if (effort > dist[r][c]) continue;
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    // The effort to move to the next cell is the MAX of 
                    // the current path effort and the difference to the next cell
                    int newEffort = max(effort, abs(heights[r][c] - heights[nr][nc]));
                    
                    if (newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return 0; 
    }
};