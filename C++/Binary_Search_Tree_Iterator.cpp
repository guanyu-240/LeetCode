/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack <TreeNode*> st;
    BSTIterator(TreeNode *root) {
        TreeNode *tmp = root;
        while (tmp != NULL) {
            st.push(tmp);
            tmp = tmp->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (st.empty()) return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        if (!hasNext()) return INT_MAX;
        TreeNode *tmp = st.top();
        int ret = tmp->val;
        st.pop();
        tmp = tmp->right;
        while (tmp != NULL) {
            st.push(tmp);
            tmp = tmp->left;
        }
        return ret;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
