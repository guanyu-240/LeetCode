class Solution {
public:
    /*
    Idea: 2D Dynamic Programming
    */
    string longestPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = s.length();
        if (len <= 1) return s;
        bool pal[len][len];
        for (int n = 0; n < len; n ++) {
            pal[n][n] = true;
        }
        
        int maxLen = 1, maxStart = 0;
        for (int i = 0; i < len; i ++){
            for (int j = i; j >= 0; j --){
                if (s[j] == s[i] && (i - j < 2 || pal[j+1][i-1])) {
                    pal[j][i] = true;
                    if (i - j + 1 > maxLen) {
                        maxLen = (i - j + 1);
                        maxStart = j;
                    }
                }
                else {pal[j][i] = false;}
            }
        }
        return s.substr(maxStart, maxLen);
    }
};
