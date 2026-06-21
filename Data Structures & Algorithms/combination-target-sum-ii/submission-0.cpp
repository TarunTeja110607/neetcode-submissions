class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;

    void backtrack(vector<int>& candidates, int target, int start) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        if (target < 0) return;

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            // i + 1 because each element can be used only once
            backtrack(candidates, target - candidates[i], i + 1);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0);

        return res;
    }
};