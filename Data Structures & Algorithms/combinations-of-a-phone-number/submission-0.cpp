class Solution {
public:
    vector<string> res;

    void backtrack(string& digits, int index,
                   string& curr,
                   unordered_map<char, string>& mp) {

        if (index == digits.size()) {
            res.push_back(curr);
            return;
        }

        string letters = mp[digits[index]];

        for (char c : letters) {
            curr.push_back(c);

            backtrack(digits, index + 1, curr, mp);

            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        string curr;
        backtrack(digits, 0, curr, mp);

        return res;
    }
};