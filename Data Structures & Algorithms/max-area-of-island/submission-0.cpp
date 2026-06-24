class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (r < 0 || c < 0 || r >= rows || c >= cols ||
            grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0; // mark visited

        return 1 +
               dfs(grid, r + 1, c) +
               dfs(grid, r - 1, c) +
               dfs(grid, r, c + 1) +
               dfs(grid, r, c - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    maxArea = max(maxArea, dfs(grid, r, c));
                }
            }
        }

        return maxArea;
    }
};