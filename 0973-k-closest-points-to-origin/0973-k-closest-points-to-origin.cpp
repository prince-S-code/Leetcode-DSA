class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // max heap: {distance, {x, y}}
        priority_queue<pair<long long, pair<int, int>>> pq;

        for (auto &point : points) {
            int x = point[0];
            int y = point[1];

            long long d = 1LL * x * x + 1LL * y * y;

            pq.push({d, {x, y}});

            // Remove the farthest point
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            ans.push_back({
                pq.top().second.first,
                pq.top().second.second
            });
            pq.pop();
        }

        return ans;
    }
};