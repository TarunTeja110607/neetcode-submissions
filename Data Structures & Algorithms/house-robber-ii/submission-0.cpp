class Solution {
public:
    int robHouse(vector<int>& nums, int l, int r) {
        int rob1 = 0, rob2 = 0;

        for (int i = l; i <= r; i++) {
            int temp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        return rob2;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        return max(robHouse(nums, 0, n - 2),
                   robHouse(nums, 1, n - 1));
    }
};