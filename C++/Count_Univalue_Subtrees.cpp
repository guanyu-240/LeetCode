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
    int countUnivalSubtrees(TreeNode* root) {
        if (root == NULL) return 0;
        int ret = 0;
        isUnivalTree(root, &ret);
        return ret;
    }
    bool isUnivalTree(TreeNode *root, int *countTotal) {
        if (root == NULL) return true;
        bool isUnivalLeft = isUnivalTree(root->left, countTotal);
        bool isUnivalRight = isUnivalTree(root->right, countTotal);
        if (isUnivalLeft && 
            isUnivalRight &&
            (root->left == NULL || root->val == root->left->val) &&
            (root->right == NULL || root->val == root->right->val)) {
            *countTotal += 1;
            return true;
        }
        return false;
    }
};
