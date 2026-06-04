class Twitter {
private:
    int timer = 0;

    struct Tweet {
        int tweetId;
        int time;
        Tweet* next;

        Tweet(int id, int t) {
            tweetId = id;
            time = t;
            next = nullptr;
        }
    };

    struct User {
        unordered_set<int> following;
        Tweet* tweetHead;

        User() { tweetHead = nullptr; }
    };

    unordered_map<int, User> users;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {

        if (users.find(userId) == users.end()) {
            users[userId] = User();
        }

        Tweet* tweet = new Tweet(tweetId, timer++);
        tweet->next = users[userId].tweetHead;
        users[userId].tweetHead = tweet;
    }

    vector<int> getNewsFeed(int userId) {

        vector<int> feed;

        if (users.find(userId) == users.end()) {
            return feed;
        }

        auto cmp = [](Tweet* a, Tweet* b) { return a->time < b->time; };

        priority_queue<Tweet*, vector<Tweet*>, decltype(cmp)> pq(cmp);

        if (users[userId].tweetHead) {
            pq.push(users[userId].tweetHead);
        }

        for (int followee : users[userId].following) {
            if (users.find(followee) != users.end() &&
                users[followee].tweetHead) {
                pq.push(users[followee].tweetHead);
            }
        }

        while (!pq.empty() && feed.size() < 10) {

            Tweet* curr = pq.top();
            pq.pop();

            feed.push_back(curr->tweetId);

            if (curr->next) {
                pq.push(curr->next);
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {

        if (followerId == followeeId) {
            return;
        }

        if (users.find(followerId) == users.end()) {
            users[followerId] = User();
        }

        if (users.find(followeeId) == users.end()) {
            users[followeeId] = User();
        }

        users[followerId].following.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        if (users.find(followerId) == users.end()) {
            return;
        }

        users[followerId].following.erase(followeeId);
    }
};