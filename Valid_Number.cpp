class Solution {
public:
    /* Finite auto-mata solution
       char index from 0 to 4 are '+/-', 'digit', 'E/e', '.', ' '.
       9 states:
          0: start
          1: +/- after start
          2: digits
          3: middle '.' discovered
          4: E/e discovered
          5: +/- after E/e
          6: digits after e
          7: beginning '.' discovered
          8: traling ' '
    */
    bool isNumber(const char *s) {
        int transitM[9][5] = {
            1, 2, -1, 7, 0,
            -1, 2, -1, 7, -1,
            -1, 2, 4, 3, 8,
            -1, 2, 4, -1, 8,
            5, 6, -1, -1, -1,
            -1, 6, -1, -1, -1,
            -1, 6, -1, -1, 8,
            -1, 2, -1, -1, -1,
            -1, -1, -1, -1, 8
        };
        int state = 0;
        const char *ptr;
        int index = -1;
        int dotCount = 0;
        ptr = s;
        while (*ptr) {
            if (*ptr++ == '.') dotCount ++;
        }
        if (dotCount >= 2) return false;
        ptr = s;
        while (*ptr) {
            index = getCharIndex(*ptr);
            if (index == -1) return false;
            state = transitM[state][index];
            if (state == -1) return false;
            ++ ptr;
        }
        
        if (state == 2 || state == 3 || state == 6 || state == 8)
            return true;
        return false;
    }
    int getCharIndex(char c) {
        if (c == '+' || c == '-') return 0;
        if (c >= '0' && c <= '9') return 1;
        if (c == 'E' || c == 'e') return 2;
        if (c == '.') return 3;
        if (c == ' ') return 4;
        return -1;
    }
};
