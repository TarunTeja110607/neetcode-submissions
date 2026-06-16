class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum > 0) {
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    res.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicate second elements
                    while (left < right &&
                           nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
            }
        }

        return res;
    }
};