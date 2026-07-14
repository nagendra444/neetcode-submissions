class Twitter {
    int timestamp;
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> following;
    // intialise priority_queue based on timestamps of tweets
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;
        for(auto tweet:tweets[userId]){
            maxHeap.push(tweet);
        }
        for(auto followee:following[userId]){
            for(auto tweet:tweets[followee]){
                maxHeap.push(tweet);
            }
        }
        vector<int> feeds;
        while (!maxHeap.empty() && feeds.size() < 10) {
        auto it = maxHeap.top();
        maxHeap.pop();

        feeds.push_back(it.second);
        }
        return feeds;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
