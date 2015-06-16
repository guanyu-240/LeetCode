class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int ret = 0;
        bool isPrime[n];
        memset(isPrime, true, sizeof(isPrime));
        double sq = sqrt((double)n);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < sq; i ++) {
            /*
            -If i is a prime, i*j should not be prime
            -If i is not a prime, i*j is already been updated, 
             no need to re-update
            */
            if (isPrime[i]) {
                for (int j = 2; j*i < n; j ++) {
                    isPrime[i*j] = false;
                }
            }
        }
        
        for (int i = 0; i < n; i ++) {
            ret += isPrime[i] ? 1 : 0;
        }
        
        return ret;
    }
};
