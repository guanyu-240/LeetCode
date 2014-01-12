/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ret;
        stack<TreeNode *> st;
        TreeNode *node = root;
        if (node == NULL) {
            return ret;
        }
        st.push(root);
        while (!st.empty()) {
            node = st.top();
            st.pop();
            ret.push_back(node->val);
            if (node->right != NULL) {
                st.push(node->right);
            }
            if (node->left != NULL) {
                st.push(node->left);
            }
        }
        return ret;
    }
};
