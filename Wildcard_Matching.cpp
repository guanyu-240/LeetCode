class Solution {
public:
    /*
    Reference: Yu's Coding Garden
    URL: http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html
    */
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char *starS = NULL, *starP = NULL;
        while (*s) {
            if (*s == *p || *p == '?') {  // matching
                s ++; p ++;
                continue;
            }
            if (*p == '*') {              // Initialize the pointer of the star
                starP = p++; starS = s;
                continue;
            }
            if (starP != NULL) {          // move forward the end point of the covering of '*'
                p = starP + 1;
                s = ++starS;
                continue;
            }
        }
        while (*p == '*') p++;
        if (*p) return false;
        return true;
    }
};
