class Solution {
public:
    /*
    Dynamic Programming:
    Recursion-1(to determine a string from j to i is palindrome):
    If s[j] = s[i] and one of the following 
        1.isPalindrome[j+1, i-1] = true
        2.i - j < 2
    isPalindrome[j][i] = true
    Recursion-2(to determine the minimum cuts ending at i):
    If isPalindrome[j][i] = true:
    minCut[i] = min(minCut[i], minCut[j] + 1)
    */
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        if (len == 0) {
            return 0;
        }
        int mincut[len];
        bool isPal[len][len];
        for (int n = 0; n < len; n ++){
            mincut[n] = n;
            isPal[n][n] = true;
        }
        
        for (int i = 0; i < len; i ++) {
            for (int j = i; j >= 0; j --) {
                if (s[j] == s[i] && (i - j < 2 || isPal[j+1][i-1])){
                    isPal[j][i] = true;
                    mincut[i] = min(mincut[i], (j == 0 ? 0 : 1 + mincut[j-1]));
                }
                else {
                    isPal[j][i] = false;
                }
            }
        }
        return mincut[len-1];
    }
};
