class Solution {
public:
    /*
    Scan from left to right.
    On each step, calculate the diff between current price and the mim price before the current day
    */
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0){
            return 0;
        }
        int len = prices.size();
        int start = prices[0];
        int end = prices[0];
        int max = end - start;
        for (int n = 0; n < len; n ++){
            if (prices[n] <= start){
                start = prices[n];
                end = start;
            }
            else{
                end = prices[n];
                max = (end - start >= max) ? end - start : max;
            }
        }
        return max;
    }
};
