class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isWord = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(string& word, int j, TrieNode* node) {
        TrieNode* cur = node;

        for (int i = j; i < word.size(); i++) {
            char c = word[i];

            if (c == '.') {
                for (TrieNode* child : cur->children) {
                    if (child && dfs(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            }

            int idx = c - 'a';
            if (!cur->children[idx]) {
                return false;
            }

            cur = cur->children[idx];
        }

        return cur->isWord;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* cur = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!cur->children[idx]) {
                cur->children[idx] = new TrieNode();
            }

            cur = cur->children[idx];
        }

        cur->isWord = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};
