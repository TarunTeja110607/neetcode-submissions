class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int hold = -prices[0];
        int sold = 0;
        int rest = 0;

        for (int i = 1; i < prices.size(); i++) {
            int prevSold = sold;

            sold = hold + prices[i];
            hold = max(hold, rest - prices[i]);
            rest = max(rest, prevSold);
        }

        return max(sold, rest);
    }
};