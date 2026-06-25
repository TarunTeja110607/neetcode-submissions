class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& vis) {
        vis[node] = true;

        for (int nei : graph[node]) {
            if (nei == parent) continue;

            if (vis[nei]) return false;   // Cycle detected

            if (!dfs(nei, node, graph, vis))
                return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> graph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);

        if (!dfs(0, -1, graph, vis))
            return false;

        // Check if all nodes are connected
        for (bool v : vis) {
            if (!v) return false;
        }

        return true;
    }
};