class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1Count(26, 0);
        vector<int> window(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            s1Count[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        if (s1Count == window) return true;

        for (int r = s1.size(); r < s2.size(); r++) {
            window[s2[r] - 'a']++;                     // add new char
            window[s2[r - s1.size()] - 'a']--;         // remove old char

            if (s1Count == window) return true;
        }

        return false;
    }
};