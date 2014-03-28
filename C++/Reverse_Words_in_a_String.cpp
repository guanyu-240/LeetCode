class Solution {
public:
    void reverseWords(string &s) {
        int n = s.length();
        if (n == 0) return;
        // remove the additional spaces and reverse every word within string
        int i = -1, j = 0;
        int x = -1, y = 0;
        while (j < n) {
            if (s[j] == ' ' && (i == -1 || j == 0 || j == n-1 || s[j+1] == ' ')) j ++;
            else {
                i ++;
                s[i] = s[j];
                if (s[i] == ' ') {
                    y = i - 1;
                    if (x == -1) x = 0;
                    reverseSubstr(s, x, y);
                    x = i + 1;
                }
                j ++;
            }
        }
        if (x == -1) x = 0;
        reverseSubstr(s, x, i);
        // resize the string
        n = i + 1;
        s.resize(n);
        // then reverse the whole string
        reverseSubstr(s, 0, n-1);
    }
    
private:
    void reverseSubstr(string &s, int x, int y) {
        char tmp;
         while (x < y) {
            tmp = s[x];
            s[x] = s[y];
            s[y] = tmp;
            x ++; y --;
        }
    }
};
