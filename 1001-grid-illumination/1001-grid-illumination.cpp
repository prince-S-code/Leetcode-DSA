class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> rows, cols, diag1, diag2;
        set<pair<int, int>> active_lamps;

        for (auto& lamp : lamps) {
            int r = lamp[0], c = lamp[1];
            if (active_lamps.insert({r, c}).second) { // Only if lamp is new
                rows[r]++;
                cols[c]++;
                diag1[r - c]++;
                diag2[r + c]++;
            }
        }

        vector<int> result;
        for (auto& q : queries) {
            int r = q[0], c = q[1];

            if (rows[r] > 0 || cols[c] > 0 || diag1[r - c] > 0 || diag2[r + c] > 0) {
                result.push_back(1);
            } else {
                result.push_back(0);
            }
            for (int i = r - 1; i <= r + 1; ++i) {
                for (int j = c - 1; j <= c + 1; ++j) {
                    if (active_lamps.erase({i, j})) { // If a lamp was actually there
                        rows[i]--;
                        cols[j]--;
                        diag1[i - j]--;
                        diag2[i + j]--;
                    }
                }
            }
        }
        return result;
    }
};