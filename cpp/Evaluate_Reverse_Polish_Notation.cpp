class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        stack<int> st;
        int len = tokens.size();
        int num1 = 0, num2 = 0;
        int ret = 0;
        for (int n = 0; n < len; n ++) {
            if (tokens[n] == "+" || tokens[n] == "-" || tokens[n] == "*" || tokens[n] == "/"){
                calculate(st, tokens[n][0]);    
            }
            else {
                st.push(atoi(tokens[n].c_str()));
            }
        }
        if (!st.empty()) {
            ret = st.top();
            st.pop();
        }
        return ret;
    }
    
    void calculate(stack<int> &st, char op){
        int num2 = st.top();
        st.pop();
        int num1 = st.top();
        st.pop();
        int ret = 0;
        switch (op){
            case '+': 
                ret = num1 + num2;
                break;
            case '-':
                ret = num1 - num2;
                break;
            case '*':
                ret = num1 * num2;
                break;
            case '/':
                ret = num1 / num2;
                break;
            default:
                ret = 0;
        }
        st.push(ret);
    }
};
