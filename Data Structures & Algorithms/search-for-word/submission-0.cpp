class Solution {
public:
    int rows, cols;

    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int index) {

        if (index == word.size())
            return true;

        if (r < 0 || c < 0 || r >= rows || c >= cols ||
            board[r][c] != word[index])
            return false;

        char temp = board[r][c];
        board[r][c] = '#'; // mark visited

        bool found =
            dfs(board, word, r + 1, c, index + 1) ||
            dfs(board, word, r - 1, c, index + 1) ||
            dfs(board, word, r, c + 1, index + 1) ||
            dfs(board, word, r, c - 1, index + 1);

        board[r][c] = temp; // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(board, word, r, c, 0))
                    return true;
            }
        }

        return false;
    }
};
