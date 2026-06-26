class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        unordered_set<int> visit;

        // {time, row, col}
        minHeap.push({grid[0][0], 0, 0});

        vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!minHeap.empty()) {
            auto cur = minHeap.top();
            minHeap.pop();

            int time = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (visit.count(r * n + c))
                continue;

            visit.insert(r * n + c);

            if (r == n - 1 && c == n - 1)
                return time;

            for (auto &[dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    !visit.count(nr * n + nc)) {

                    minHeap.push({max(time, grid[nr][nc]), nr, nc});
                }
            }
        }

        return -1;
    }
};