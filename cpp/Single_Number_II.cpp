class Solution {
public:
    /*
    O(1) space complexity
    Use a 32 size array to store the number of '1' s in every bit. If the ith bit has n_i number of '1's
    and n_i % 3 != 0, the single number should have 1 in ith bit.
    */
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n == 0) return n;         
        int counts[32] = {0};
        int result = 0;
        for(int i = 0; i < 32; i++){
            for(int j = 0; j < n; j++){
                if(((A[j] >> i) & 1) == 1){
                    counts[i] = (counts[i] + 1) % 3;
                }
            }
            result |= (counts[i] << i);
        }
        return result;
    }
};
