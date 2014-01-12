class Solution {
public:
    /*
    Sum of all the positive profits between two days.
    Because the positive profit gained from i to j equals the sum of all the positive profit between 2 days from i to j.
    */
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0){
            return 0;
        }
        int len = prices.size();
        int max = 0;
        for (int n = 1; n < len; n ++){
            int profit_tmp = prices[n] - prices[n - 1];
            if (profit_tmp > 0){
                max += profit_tmp;
            }
        }
        return max;
    }
};
