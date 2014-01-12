class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lenT = T.length();
        int len = S.length();
        if (lenT == 0) return T;
        int counts[256];
        int expectedCounts[256];
        fill_n(counts, 256, 0);
        fill_n(expectedCounts, 256, 0);
        for (int n = 0; n < lenT; n ++){
            expectedCounts[T[n]] ++;
        }
        int start = 0, covered = 0;
        int minLen = INT_MAX, minStart = -1;
        for (int n = 0; n < len; n ++) {
            char c = S[n];
            if (expectedCounts[c] > 0){
                counts[c] ++;
                if (counts[c] <= expectedCounts[c]) {
                    covered ++;
                }
            }
            if (covered == lenT) {
                while (expectedCounts[S[start]] == 0 || counts[S[start]] > expectedCounts[S[start]]) {
                    if (counts[S[start]] > 0) {
                        counts[S[start]] --;
                    }
                    start ++;
                }
                if (n - start + 1 <= minLen) {
                    minLen = n - start + 1;
                    minStart = start;
                }
            }
        }
        
        if (minStart == -1 || minLen == INT_MAX) {return "";}
        return S.substr(minStart, minLen);
    }
};
