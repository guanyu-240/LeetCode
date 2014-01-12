class Solution {
public:
    int atoi(const char *str) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        char *start = (char *)str;
        while ((*start) && (*start == ' ')){
            start ++;
        }
        if (!(*start)) return 0;
        long long base = 1;
        char c = *start;
        if (c == '-' || c == '+'){
            base = (c == '-' ? -1 : 1);
            start ++;
        }
        stack<int> st;
        while (*start){
            c = *start;
            if (c > '9' || c < '0') break;
            st.push(c - '0');
            start ++;
        }
        long long ret = 0;
        while(!st.empty()) {
            long long tmp = st.top() * base;
            if (ret + tmp > INT_MAX) return INT_MAX;
            if (ret + tmp < INT_MIN) return INT_MIN;
            ret += tmp;
            base *= 10;
            st.pop();
        }
        return ret;
    }
    
};
