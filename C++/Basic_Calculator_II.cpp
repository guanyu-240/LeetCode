class Solution {
public:
    int calculate(string s) {
        s.append(1, '!');
        stack<int>st;
        int num=0, tmpNum=0, ret=0;
        char current_op = '\0', previous_op = '\0';
        for (string::iterator it=s.begin(); it != s.end(); ++it) {
            if (*it == ' ') { continue; }
            else if (*it >= '0' && *it <= '9') {
                num = num*10 + (*it - '0');
            }
            else {
                current_op = *it;
                if (previous_op == '-') {
                    num *= -1;
                }
                else if (previous_op == '*' || previous_op == '/') {
                    tmpNum = st.empty() ? 0 : st.top();
                    st.pop();
                    num = (previous_op == '*' ? tmpNum*num : tmpNum/num);
                }
                st.push(num);
                num = 0;
                previous_op = current_op;
            }
        }

        while (!st.empty()) {
            ret += st.top();
            st.pop();
        }
        return ret;
    }
};
