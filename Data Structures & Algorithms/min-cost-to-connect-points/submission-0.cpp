class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // Adjacency list: {neighbor, cost}
        unordered_map<int, vector<pair<int, int>>> adj;

        // Build complete graph
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        int cost = 0;
        unordered_set<int> visit;

        // {weight, node}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> minHeap;

        minHeap.push({0, 0});

        while (visit.size() < n) {
            auto [wt, node] = minHeap.top();
            minHeap.pop();

            if (visit.count(node))
                continue;

            visit.insert(node);
            cost += wt;

            for (auto &[nei, w] : adj[node]) {
                if (!visit.count(nei)) {
                    minHeap.push({w, nei});
                }
            }
        }

        return cost;
    }
};