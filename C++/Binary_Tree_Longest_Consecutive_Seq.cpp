/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int ret = 0;
        helper(root, &ret);
        return ret;
    }
    int helper(TreeNode* root, int *ret) {
        if (root == NULL) return 0;
        int left_ret = helper(root->left, ret);
        left_ret = 1 + ((root->left != NULL && root->left->val == root->val+1) ? left_ret : 0);
        *ret = max(left_ret, *ret);
        int right_ret = helper(root->right, ret);
        right_ret = 1 + ((root->right != NULL && root->right->val == root->val+1) ? right_ret : 0);
        *ret = max(right_ret, *ret);
        return max(left_ret, right_ret);
    }
};
