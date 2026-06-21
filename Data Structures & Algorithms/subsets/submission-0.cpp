class Solution {
public:
    vector<vector<int>> result;
    vector<int> subset;

    void backtrack(vector<int>& nums, int i) {
        if (i == nums.size()) {
            result.push_back(subset);
            return;
        }

        // Include nums[i]
        subset.push_back(nums[i]);
        backtrack(nums, i + 1);

        // Exclude nums[i]
        subset.pop_back();
        backtrack(nums, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};