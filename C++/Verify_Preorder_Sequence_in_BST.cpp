class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        /*
        Using a stack to simulate the pre-order traversal
        */
        if (preorder.size() <= 1) return true;
        stack<int> st;
        int lower_bound = INT_MIN;
        for (int x : preorder) {
            if (x < lower_bound) return false;
            while (!st.empty() && st.top() < x) {
                lower_bound = st.top();
                st.pop();
            }
            st.push(x);
        }
        return true;
    }
};
