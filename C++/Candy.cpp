class Solution {
public:
    /*
    Idea: Similar to Greedy.
    Scan the array twice.
    First time, scan and try using minimum candies to satisfy the increasing series from left to right.
    Second time, scan and try using minimum candies to satisfy the increasing series from right to left,
    which means adding minimum candies on the previous result to satisfy the series from right to left.
    */
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = ratings.size();
        if (len == 0) {
            return 0;
        }
        int candy[len];
        for (int i = 0; i < len; i ++) {
            if (i == 0 || (i > 0 && ratings[i] > ratings[i-1])) {
                candy[i] = i == 0 ? 1 : candy[i-1] + 1;
            }
            else {
                candy[i] = 1;
            }
        }
        
        for (int i = len - 1; i >= 0; i --) {
            if (i < len - 1 && ratings[i] > ratings[i+1]){
                if (candy[i] <= candy[i+1]) {
                    candy[i] = candy[i+1] + 1;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < len; i ++) {
            sum += candy[i];
        }
        return sum;
    }
};
