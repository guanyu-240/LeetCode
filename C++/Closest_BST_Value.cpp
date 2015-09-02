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
    int closestValue(TreeNode* root, double target) {
        double lb = (double)INT_MIN-1;
        double ub = (double)INT_MAX+1;
        while (root != NULL) {
            if (root->val > target) {
                ub = root->val;
                root = root->left;
            }
            else {
                lb = root->val;
                root = root->right;
            }
        }
        if (lb == (double)INT_MIN-1) return (int)ub;
        else if (ub == (double)INT_MAX+1) return (int)lb;
        else return ub + lb > 2*target ? (int)lb : (int)ub;
    }
};
