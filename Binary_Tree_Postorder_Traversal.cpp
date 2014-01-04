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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ret;
        if (root == NULL) return ret;
        stack<TreeNode*>st;
        st.push(root);
        while (!st.empty()){
            TreeNode *node = st.top();
            st.pop();
            ret.insert(ret.begin(), node->val);
            if (node->left != NULL){
                st.push(node->left);
            }
            if (node->right != NULL) {
                st.push(node->right);
            }
        }
        return ret;
    }
};
