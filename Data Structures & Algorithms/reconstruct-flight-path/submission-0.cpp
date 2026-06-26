class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> itinerary;

    void dfs(string src) {
        auto &pq = adj[src];

        while (!pq.empty()) {
            string next = pq.top();
            pq.pop();
            dfs(next);
        }

        itinerary.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto &ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");

        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};