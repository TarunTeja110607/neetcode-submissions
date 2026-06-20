class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            greater<pair<int, vector<int>>>
        > minHeap;

        for (auto& p : points) {
            int dist = p[0] * p[0] + p[1] * p[1];
            minHeap.push({dist, p});
        }

        vector<vector<int>> res;

        while (k--) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};