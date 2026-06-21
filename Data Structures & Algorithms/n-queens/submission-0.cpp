class Solution {
public:
    vector<vector<string>> res;
    unordered_set<int> cols;
    unordered_set<int> diag1; // row - col
    unordered_set<int> diag2; // row + col

    void backtrack(int row, int n, vector<string>& board) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (cols.count(col) ||
                diag1.count(row - col) ||
                diag2.count(row + col))
                continue;

            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            board[row][col] = 'Q';

            backtrack(row + 1, n, board);

            board[row][col] = '.';

            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        backtrack(0, n, board);

        return res;
    }
};