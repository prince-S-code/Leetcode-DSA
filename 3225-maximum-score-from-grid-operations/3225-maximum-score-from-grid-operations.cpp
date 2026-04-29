#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        const long long MIN_INF = -1e18; // Safe lower bound
        
        // pref[j][i] = sum of the first i elements in column j
        vector<vector<long long>> pref(n, vector<long long>(n + 1, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                pref[j][i + 1] = pref[j][i] + grid[i][j];
            }
        }
        
        // dp[h][0] -> current col has height h, is NOT scored by the right neighbor
        // dp[h][1] -> current col has height h, IS scored by the right neighbor
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        
        for (int i = 1; i < n; i++) {
            vector<vector<long long>> next_dp(n + 1, vector<long long>(2, 0));
            
            // max_C: The best score if neither column scores the other (Option C)
            long long max_C = 0;
            for (int k = 0; k <= n; k++) {
                max_C = max(max_C, dp[k][0]);
            }
            
            // Precalculate Suffix Maximums for Option A (k > j)
            vector<long long> suf_max_A(n + 2, MIN_INF); 
            for (int k = n; k >= 0; k--) {
                suf_max_A[k] = max(suf_max_A[k + 1], dp[k][0] + pref[i][k]);
            }
            
            // Precalculate Prefix Maximums for Option B (k < j)
            vector<long long> pref_max_B(n + 1, MIN_INF); 
            long long current_max = MIN_INF;
            for (int k = 0; k <= n; k++) {
                current_max = max(current_max, dp[k][1] - pref[i - 1][k]);
                pref_max_B[k] = current_max;
            }
            
            // Calculate states for the current column
            for (int j = 0; j <= n; j++) {
                // Initialize with Option C
                next_dp[j][0] = max_C;
                next_dp[j][1] = max_C;
                
                // Option A: Left neighbor (i-1) scores current column (i)
                if (j + 1 <= n) {
                    next_dp[j][0] = max(next_dp[j][0], suf_max_A[j + 1] - pref[i][j]);
                }
                
                // Option B: Current column (i) scores left neighbor (i-1)
                if (j - 1 >= 0) {
                    long long valB = pref_max_B[j - 1] + pref[i - 1][j];
                    next_dp[j][0] = max(next_dp[j][0], valB);
                    next_dp[j][1] = max(next_dp[j][1], valB);
                }
            }
            
            dp = next_dp;
        }
        
        // Find the maximum score in the final column
        long long ans = 0;
        for (int h = 0; h <= n; h++) {
            // The last column cannot be scored by a right neighbor, so we only check state 0
            ans = max(ans, dp[h][0]); 
        }
        
        return ans;
    }
};