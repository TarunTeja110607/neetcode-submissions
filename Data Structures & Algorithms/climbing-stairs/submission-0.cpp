class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;

        int one = 2;
        int two = 1;

        for (int i = 3; i <= n; i++) {
            int temp = one + two;
            two = one;
            one = temp;
        }

        return one;
    }
};