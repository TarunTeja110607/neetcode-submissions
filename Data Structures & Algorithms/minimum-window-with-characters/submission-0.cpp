class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> countT, window;

        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        int resLen = INT_MAX;
        int resL = 0;

        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    resL = l;
                }

                window[s[l]]--;

                if (countT.count(s[l]) &&
                    window[s[l]] < countT[s[l]]) {
                    have--;
                }

                l++;
            }
        }

        return resLen == INT_MAX
               ? ""
               : s.substr(resL, resLen);
    }
};