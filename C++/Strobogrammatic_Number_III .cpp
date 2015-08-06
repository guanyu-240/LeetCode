class Solution {
private:
    vector<string> digits{ "00", "11", "69", "88", "96" };
    vector<string> digits_mid{ "0", "1", "8" };
public:
    int strobogrammaticInRange(string low, string high) {
        int n1 = low.length(), n2 = high.length();
        if (n1 > n2 || n2 == 0 || (n1 == n2 && low.compare(high) > 0)) return 0;
        return countSmaller(high, true) - countSmaller(low, false);
    }
    
    /* Count the numbers smaller than x */
    int countSmaller(string x, bool equal) {
        int n = x.length();
        if (n == 0) return 0;
        int ret = 0, i = 1;
        while (i < n) {
            ret += countSTBG(i++, '\0');
        }
        ret += countSTBG(n, x[0]);
        if (!isSTBG(x[0], n)) return ret;
        vector<string> cand = constructSolutions(n, x[0]);
        for (string s : cand) {
            if (s.compare(x) < 0) { ret ++; }
            else if (s.compare(x) == 0 && equal) { ret ++; }
        }
        return ret;
    }
    
    /* Count the numbers with n digits and first digit smaller than x */
    long long countSTBG(int n, char x) {
        if (n == 0) return 0;
        
        int first = 0;          // count the possibility of first digits
        if (x == '\0') { first = (n == 1) ? 3 : 4; }
        else if (x == '0') { first = 0; }
        else if (x == '1') { first = (n == 1 ? 1 : 0); }
        else if (x <= '6') { first = (n == 1 ? 2 : 1); }
        else if (x <= '8') { first = 2; }
        else { first = 3; }
        
        if (n == 1) { return first; }
        else if (n%2 == 0) { return first*(long long)pow(5,n/2-1); }
        else { return first*(long long)pow(5, n/2-1)*3; } 
    }
    
    /* construct strobogrammic numbers with n digits and first digit is f */
    vector<string> constructSolutions(int n, char f) {
        if (n <= 0) return vector<string>(1, "");
        else if (n == 1){
            return f == '\0' ? digits_mid : vector<string> { string(1,f)+"" };
        }
        else {
            vector<string> ret;
            vector<string> tmp = constructSolutions(n-2, '\0');
            for (string s : tmp) {
                if (f != '\0') {
                    if (f == '6') ret.push_back("6"+s+"9");
                    else if (f == '9') ret.push_back("9"+s+"6");
                    else ret.push_back(string(1,f)+s+string(1,f));
                }
                else {
                    for (string d : digits) ret.push_back(d[0]+s+d[1]);
                }
            }
            return ret;
        }
    }
    bool isSTBG(char c, int n) {
        return c == '0' || 
                c == '1' || 
                c =='8' || 
                (c == '6' && n > 1) ||
                (c == '9' && n > 1);
    }
};
