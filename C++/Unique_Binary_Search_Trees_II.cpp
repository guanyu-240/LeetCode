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
    vector<TreeNode *> generateTrees(int n) {
        return solve(1, n);
    }
    
    vector<TreeNode *> solve(int left, int right) {
        vector<TreeNode *> ret;
        if (left > right) {
            ret.push_back(NULL);
            return ret;
        }
        for (int i = left; i <= right; i ++) {
            vector<TreeNode *> leftTrees = solve(left, i-1);
            vector<TreeNode *> rightTrees = solve(i+1, right);
            for (TreeNode *leftRoot : leftTrees) {
                for (TreeNode *rightRoot : rightTrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};
