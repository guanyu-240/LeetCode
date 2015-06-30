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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int h_left = 0, h_right = 0;
        TreeNode *tmp = root;
        int ret = 1;
        /* Try to find the break node and its sequence number */
        while (tmp->left != NULL || tmp->right != NULL) {
            h_left = countHeight(tmp->left);
            h_right = countHeight(tmp->right);
            if (h_left == h_right ) {
                tmp = tmp->right;
                ret = 2*ret + 1;
            }
            else {
                tmp = tmp->left;
                ret = 2*ret;
            }
        }
        return ret;
    }
    
    int countHeight(TreeNode *root) {
        int ret = 0;
        while (root != NULL) {
            ret ++;
            root = root->left;
        }
        return ret;
    }
};
