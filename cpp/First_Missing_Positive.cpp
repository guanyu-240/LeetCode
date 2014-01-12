class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i = n - 1;
        while (i >= 0) {
            if (A[i] <= 0 || A[i] == i + 1) {
                i --;
            }
            else {
                int tmp = A[i];
                if (tmp > n || A[tmp - 1] == tmp) {
                    i --;
                }
                else {
                    A[i] = A[tmp - 1];
                    A[tmp - 1] = tmp;
                }
            }
        }
        for (i = 0; i < n; i ++) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
