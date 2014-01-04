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
    int maxVal;
    int maxSubTree;
    int maxEndHere;
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        maxVal = INT_MIN;
        maxPathEndAtCurrent(root);
        return maxVal;
    }
    
    /*
    For every node, there are several candidates which might contribute to
    maximum sum path END AT THE CURRENT NODE, let it be max_end_here(node):
    max_end_here(left) + node
    max_end_here(right) + node
    node it self
    There are several candidates(related to the current node) that will contribute to max value to return:
    node + leftmax
    node + rightmax
    node it self
    node + leftmax + rightmax
    And the max of first 3 will be selected to max_end_here(current)
    */
    int maxPathEndAtCurrent(TreeNode *root){
        if (root == NULL) return 0;
        int leftMax = maxPathEndAtCurrent(root->left);
        int rightMax = maxPathEndAtCurrent(root->right);
        maxSubTree = max(leftMax, rightMax);
        maxEndHere = max(root->val, maxSubTree + root->val);
        maxVal = max(maxEndHere, maxVal);
        maxVal = max(maxVal, leftMax+rightMax+root->val);
        return maxEndHere;
    }
};
