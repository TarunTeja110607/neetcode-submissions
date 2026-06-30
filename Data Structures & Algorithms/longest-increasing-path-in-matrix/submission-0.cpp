class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1;

        for (auto &[dx, dy] : dir) {
            int x = i + dx;
            int y = j + dy;

            if (x >= 0 && x < m && y >= 0 && y < n &&
                matrix[x][y] > matrix[i][j]) {
                ans = max(ans, 1 + dfs(matrix, x, y));
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, -1));

        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(matrix, i, j));
            }
        }

        return res;
    }
};