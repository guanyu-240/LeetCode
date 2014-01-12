class Solution {
public:
    /*
    Idea: dividend = divisor(a(n)2^n + a(n - 1)2^(n - 1) + ... + a(1)2^1 + a(0)2^0)
    a(i) = 1 or 0 (0 <= i <= n)
    From high to low, calculate a(n)
    Each time, shift divisor by i when shifting 1 more bit will cause (dividend - divisor) < 0
    In this process we can get an divisor*2^i. 2^i will be the part of the return value. 
    Then decrement the dividend by divisor*2^i.
    Do this process again and again until dividend equals 0.
    In this way, any bit i in which a(i) = 0 will be skipped. 
    */
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long dividendNew = abs((long long)dividend);
        long long ret = 0;
        while (dividendNew > 0){
            long long divisorNew = abs((long long)divisor);
            int shifted = 0;
            while (dividendNew - divisorNew >= 0){
                divisorNew <<= 1;
                shifted ++;
            }
            shifted --;
            if (shifted >= 0){
                ret += (1<<shifted);
                divisorNew >>= 1;
            }
            dividendNew -= divisorNew;
        }
        return ((dividend^divisor) >= 0) ? (int)ret : -(int)ret;
    }
};
