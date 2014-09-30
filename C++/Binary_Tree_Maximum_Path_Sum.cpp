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
    /*
    For every root, there are 4 candidate paths(across this root) for maximum path sum
    root only
    root + <max weight path ending at left child>
    root + <max weight path ending at right child>
    root + <max weight path ending at left child> + <max weight path ending at right child>
    */
private:
    int maxPath;
    int maxAcrossThisRoot;
    int maxEndThisRoot(TreeNode *root){
        if (root == NULL) return 0;
        int maxEndL = maxEndThisRoot(root->left);
        int maxEndR = maxEndThisRoot(root->right);
        maxAcrossThisRoot = root->val + max(maxEndL, 0) + max(maxEndR, 0);
        maxPath = max(maxPath, maxAcrossThisRoot);
        return root->val + max(max(maxEndL, maxEndR), 0);
    }
public:
    int maxPathSum(TreeNode *root) {
        maxPath = INT_MIN;
        maxEndThisRoot(root);
        return maxPath;
    }
};
