public class Twitter {
    
    /* members */
    private HashMap<Integer, User> users;
    private int ts;
    
    /** Initialize your data structure here. */
    public Twitter() {
        ts = 0;
        users = new HashMap<Integer, User>();
    }
    
    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        /* Add tweet to user-tweet map */
        if (!users.containsKey(userId)) {
            users.put(userId, new User());
        }
        User u = users.get(userId);
        u.addTweet(tweetId, ts);
        ts ++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        User u = users.get(userId);
        if (u == null) return new LinkedList<Integer>();
        return u.getNewsFeed();
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        User follower = users.get(followerId), followee = users.get(followeeId);
        if (follower == null) {
            follower = new User();
            users.put(followerId, follower);
        }
        if (followee == null) {
            followee = new User();
            users.put(followeeId, followee);
        }
        followee.addFollower(follower);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        User follower = users.get(followerId), followee = users.get(followeeId);
        if (follower == null || followee == null) return;
        followee.rmFollower(follower);
    }
    
    
    
    /* Definition of Tweet structure */
    private static class Tweet implements Comparable<Tweet>{
        private int tweetId;
        private int ts;
        public Tweet (int tweetId, int ts) {
            this.tweetId = tweetId;
            this.ts = ts;
        }
        @Override
        public int compareTo(Tweet other){
            return other.ts - ts;
        }
    }
    /* Definition of User structure*/
    private static class User {
        private HashSet<User> followers;
        private PriorityQueue<Tweet> news;
        private LinkedList<Tweet> tweets;
        public User(){
            followers = new HashSet<User>();
            news = new PriorityQueue<Tweet>();
            tweets = new LinkedList<Tweet>();
        }
        public void addTweet(int tweetId, int ts) {
            Tweet t = new Tweet(tweetId, ts);
            tweets.add(t);
            news.add(t);
            for (User u: followers) {
                u.addToNews(t);
            }
        }
        public List<Integer> getNewsFeed() {
            List<Integer> ret = new LinkedList<Integer>();
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
        public void addToNews(Tweet t){
            news.add(t);
        }
        public void removeFromNews(Tweet t) {
            news.remove(t);
        }
        public void addFollower(User follower){
            if (follower == null || followers.contains(follower)) return;
            followers.add(follower);
            for (Tweet t : tweets) {
                follower.addToNews(t);
            }
        }
        public void rmFollower(User follower) {
            if (follower == null || !followers.contains(follower)) return;
            followers.remove(follower);
            for (Tweet t : tweets) {
                follower.removeFromNews(t);
            }
        }
    }
    /**/
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
