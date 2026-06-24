class Solution {
    struct TrieNode {
        TrieNode* children[26];
        string word;

        TrieNode() {
            word = "";
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;
    vector<string> result;
    int rows, cols;

    void insert(string& word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        char ch = board[r][c];

        if (ch == '#' || !node->children[ch - 'a']) {
            return;
        }

        node = node->children[ch - 'a'];

        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";   // avoid duplicates
        }

        board[r][c] = '#';

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nr < rows &&
                nc >= 0 && nc < cols) {
                dfs(board, nr, nc, node);
            }
        }

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        root = new TrieNode();

        for (string& word : words) {
            insert(word);
        }

        rows = board.size();
        cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root);
            }
        }

        return result;
    }
};