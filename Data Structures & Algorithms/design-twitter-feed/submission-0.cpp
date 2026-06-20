class Twitter {
private:
    int timeStamp;

    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int, int>>> tweetMap;

public:
    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({timeStamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        followMap[userId].insert(userId);

        priority_queue<vector<int>> maxHeap;

        for (int followee : followMap[userId]) {
            auto& tweets = tweetMap[followee];

            if (!tweets.empty()) {
                int idx = tweets.size() - 1;

                maxHeap.push({
                    tweets[idx].first,   // timestamp
                    tweets[idx].second,  // tweetId
                    followee,
                    idx
                });
            }
        }

        while (!maxHeap.empty() && res.size() < 10) {
            auto curr = maxHeap.top();
            maxHeap.pop();

            int tweetId = curr[1];
            int followee = curr[2];
            int idx = curr[3];

            res.push_back(tweetId);

            idx--;

            if (idx >= 0) {
                auto& tweets = tweetMap[followee];

                maxHeap.push({
                    tweets[idx].first,
                    tweets[idx].second,
                    followee,
                    idx
                });
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followMap.count(followerId)) {
            followMap[followerId].erase(followeeId);
        }
    }
};