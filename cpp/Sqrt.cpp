class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x == 0 || x == 1) return x;
        long long start = 0, end = x;
        long long mid;
        long long square;
        while (start <= end){
            mid = (start + end) / 2;
            square = mid * mid;
            if (square < x){
                start = mid + 1;
            }
            else if (square > x){
                end = mid - 1;
            }
            else{
                return (int)mid;
            }
        }
        mid = (start + end) / 2;
        return (int)mid;
    }
};
