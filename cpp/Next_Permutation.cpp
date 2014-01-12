class Solution {
public:
    /*
    Find the partial maximum permutation.
    Exchange:
    the element before the 'partial maximum'
    and
    the first number higher than this element within the 'partial maximum' 
    */
    void nextPermutation(vector<int> &num) {
        int len = num.size();
        if (len <= 1) return;
        bool found = false;
        int noInc = len - 1;
        for (int n = len - 2; n >= 0; n--) {
            if (num[n] < num[n+1]) {
                break;
            }
            noInc = n;
        }
        reverse(num.begin()+noInc, num.end());
        if (noInc > 0) {
            for (int i = noInc; i < len; i ++) {
                if (num[i] > num[noInc-1]) {
                    swap(num[i], num[noInc-1]);
                    break;
                }
            }
        }
    }
};
