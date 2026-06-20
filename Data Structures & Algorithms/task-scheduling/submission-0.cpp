class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> count;

        for (char task : tasks) {
            count[task]++;
        }

        priority_queue<int> maxHeap;
        for (auto& [task, freq] : count) {
            maxHeap.push(freq);
        }

        queue<pair<int, int>> q; // {remainingCount, readyTime}
        int time = 0;

        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int freq = maxHeap.top();
                maxHeap.pop();

                freq--;

                if (freq > 0) {
                    q.push({freq, time + n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};