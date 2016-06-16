public class Twitter {
    /* Definition of Tweet structure */
    class Tweet implements Comparable<Tweet>{
        int userId;
        int tweetId;
        int ts;
        public Tweet (int userId, int tweetId, int ts) {
            this.userId = userId;
            this.tweetId = tweetId;
            this.ts = ts;
        }
        @Override
        public int compareTo(Tweet other){
            return other.ts - ts;
        }
    }
    /**/
    
    /* members */
    private HashMap<Integer, HashSet<Integer>> followersMap;
    private HashMap<Integer, PriorityQueue<Tweet>> newsMap;
    private HashMap<Integer, HashSet<Tweet>> uid_tweetMap;
    private int ts;
    
    /** Initialize your data structure here. */
    public Twitter() {
        ts = 0;
        followersMap = new HashMap<Integer, HashSet<Integer>>();
        newsMap = new HashMap<Integer, PriorityQueue<Tweet>>();
        uid_tweetMap = new HashMap<Integer, HashSet<Tweet>>();
    }
    
    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        Tweet t = new Tweet(userId, tweetId, ts);
        /* Add tweet to user-tweet map */
        if (!uid_tweetMap.containsKey(userId)) {
            uid_tweetMap.put(userId, new HashSet<Tweet>());
        }
        HashSet<Tweet> tweets = uid_tweetMap.get(userId);
        tweets.add(t);
        /* add the tweet to the news of his/her followers */
        if (!followersMap.containsKey(userId)) {
            followersMap.put(userId, new HashSet<Integer>());
        }
        HashSet<Integer> followers = followersMap.get(userId);
        followers.add(userId);
        for (int follower : followers) {
            if (!newsMap.containsKey(follower)) {
                newsMap.put(follower, new PriorityQueue<Tweet>());
            }
            PriorityQueue<Tweet> news = newsMap.get(follower);
            news.add(t);
        }
        ts ++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> ret = new LinkedList<Integer>();
        PriorityQueue<Tweet> news = newsMap.get(userId);
        if (news == null) return ret;
        Queue<Tweet> tmp = new LinkedList<Tweet>();
        int count = 10;
        while (!news.isEmpty() && count > 0) {
            ret.add(news.peek().tweetId);
            tmp.add(news.poll());
            count --;
        }
        while (!tmp.isEmpty()) {
            news.add(tmp.poll());
        }
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        if (!followersMap.containsKey(followeeId)) {
            followersMap.put(followeeId, new HashSet<Integer>());
        }
        HashSet<Integer> followers = followersMap.get(followeeId);
        if (followers.contains(followerId)) return;
        followers.add(followerId);
        /* Add tweets to follower's news queue */
        HashSet<Tweet> tweets = uid_tweetMap.get(followeeId);
        if (tweets == null) return;
        if (!newsMap.containsKey(followerId)) {
            newsMap.put(followerId, new PriorityQueue<Tweet>());
        }
        PriorityQueue<Tweet> news = newsMap.get(followerId);
        for (Tweet t : tweets) {
            news.add(t);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        HashSet<Integer> followers = followersMap.get(followeeId);
        if (followers == null || !followers.contains(followerId)) return;
        followers.remove(followerId);
        HashSet<Tweet> tweets = uid_tweetMap.get(followeeId);
        if (tweets == null) return;
        PriorityQueue<Tweet> news = newsMap.get(followerId);
        if (news == null) return;
        for (Tweet t : tweets) {
            news.remove(t);
        }
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
