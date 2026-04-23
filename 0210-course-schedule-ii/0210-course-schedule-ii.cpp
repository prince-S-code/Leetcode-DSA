class Solution {
    bool dfs(vector<vector<int>>& adj, int node,
             vector<int>& visited, vector<int>& path,
             vector<int>& ans) {

        visited[node] = 1;
        path[node] = 1;

        for (auto it : adj[node]) {
            if (!visited[it]) {
                if (dfs(adj, it, visited, path, ans))
                    return true;
            } 
            else if (path[it]) {
                return true; // cycle
            }
        }

        path[node] = 0;
        ans.push_back(node);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> visited(numCourses, 0), path(numCourses, 0);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(adj, i, visited, path, ans))
                    return {};
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};