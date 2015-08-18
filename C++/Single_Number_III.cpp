class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() < 2) return vector<int>();
        vector<int>ret(2,0);
        int xr = 0, tmp = 0;
        /* first getting the xor of the two numbers */
        for (int x : nums) { xr = xr ^ x; }
        /*Two numbers differ in at least one bit, 
        Assume a has bit k=1, b has bit k=0 
        then classify this array into two sub-arrays, 
        one has all numbers whose bit k=1,
        the other has all numbers whose bit k=0 */
        int mask = 1;
        while ((xr & mask) == 0) mask <<= 1;
        for (int x : nums) {
            if (x & mask) ret[1] ^= x;
        }
        ret[0] = ret[1]^xr;
        return ret;
    }
};
