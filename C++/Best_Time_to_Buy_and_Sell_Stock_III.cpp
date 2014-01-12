class Solution {
public:
    /*
    2 Steps:
    1. Scan from beginning to the end of the array, get the max profit(single transaction) from [0, i]. 
    2. Scan from end to the beginning of the array, get the max profit(single transaction) from [i, n-1].
    */
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ret = 0;
        int len = prices.size();
        if (len <= 1) {
            return ret;
        }
        int start = prices[0], end = prices[0];
        int maxV = end - start;
        int max1[len];
        // 1st scan
        for (int n = 0; n < len; n ++){
            if (prices[n] <= start){
                start = prices[n];
                end = start;
            }
            else{
                end = prices[n];
                maxV = (end - start >= maxV) ? end - start : maxV;
            }
            max1[n] = maxV;
        }
        // 2nd scan
        start = prices[len - 1];
        end = prices[len - 1];
        maxV = 0;
        for (int n = len - 1; n > 0; n --){
            if (prices[n] >= end) {
                end = prices[n];
                start = end;
            }
            else {
                start = prices[n];
                maxV = (end - start >= maxV) ? end - start : maxV;
            }
            ret = max(ret, max1[n - 1]+maxV);
        }
        ret = max(ret, max1[len - 1]);
        return ret;
    }
};
