class Solution {
public:
    /*
    Consider 2 sets, S(the smaller half), L(the bigger half). If (m+n) %2 = 1
    For numbers in S, if there are k numbers in A, there should be (m+n)/2 -k numbers in B
    Binary search until find a correct k
    */
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if ((m+n) % 2 == 0) {
            return (getKthNumber(A, m, B, n, (m+n)/2) + getKthNumber(A, m, B, n, ((m+n)/2)+1))/2.0;
        }
        else return getKthNumber(A, m, B, n, ((m+n)/2)+1);
    }
    int getKthNumber(int A[], int m, int B[], int n, int k){ // k is guarenteed to be [m, n]
        assert(A && B); 
        int leftA = 0, rightA = m-1, leftB = 0, rightB = n-1;
        int midA = 0, midB = 0;
        while (leftA <= rightA || leftB <= rightB){
            if (leftA > rightA) return B[leftB+k-1];
            if (leftB > rightB) return A[leftA+k-1];
            if (k <= 1) return min(A[leftA], B[leftB]);
            midA = (leftA + rightA)/2;
            midB = (leftB + rightB)/2;
            if (A[midA] <= B[midB]){
                if ((midA-leftA+1) + (midB-leftB+1) > k) {
                    rightB = midB - 1;
                }
                else {
                    k = k - (midA-leftA+1);
                    leftA = midA + 1;
                }
            }
            else {
                if ((midA-leftA+1) + (midB-leftB+1) > k) {
                    rightA = midA - 1;
                }
                else {
                    k = k - (midB-leftB+1);
                    leftB = midB + 1;
                }
            }
        }
        return 0;
    }
};
