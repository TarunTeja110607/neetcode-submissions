class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";

        auto &arr = mp[key];

        int left = 0;
        int right = arr.size() - 1;
        string result = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid].first <= timestamp) {
                result = arr[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};