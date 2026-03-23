class Solution {
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& color) {
        for (int neighbour : adj[node]) {
            // If not colored → assign opposite color
            if (color[neighbour] == 0) {
                color[neighbour] = -color[node];
                if (!dfs(neighbour, adj, color)) {
                    return false;
                }
            }
            // If already colored and same → conflict
            else if (color[neighbour] == color[node]) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0); // 0 = unvisited

        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                color[i] = 1;  // start coloring
                if (!dfs(i, graph, color)) {
                    return false;
                }
            }
        }

        return true;
    }
};