class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        int dp1 = 1;                          // dp[i+1]
        int dp2 = 0;                          // dp[i+2]
        int curr = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                curr = 0;
            } else {
                curr = dp1;

                if (i + 1 < n &&
                    (s[i] == '1' ||
                    (s[i] == '2' && s[i + 1] <= '6'))) {
                    curr += (i + 2 <= n - 1) ? dp2 : 1;
                }
            }

            dp2 = dp1;
            dp1 = curr;
        }

        return dp1;
    }
};