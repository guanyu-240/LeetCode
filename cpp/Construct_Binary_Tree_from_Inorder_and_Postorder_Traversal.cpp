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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return solve(inorder, 0, postorder, 0, inorder.size());
    }
    TreeNode *solve(vector<int> &inorder, int startI, vector<int> &postorder, int startP, int len){
        if (len == 0) {
            return NULL;
        }
        int rootVal = postorder[startP + len - 1];
        TreeNode *root = new TreeNode(rootVal);
        int rootOffset = 0;
        for (int n = 0; n < len; n ++) {
            if (inorder[startI + n] == rootVal){
                rootOffset = n;
                break;
            }
        }
        root->left = solve(inorder, startI, postorder, startP, rootOffset);
        root->right = solve(inorder, startI+rootOffset+1, postorder, startP+rootOffset, len-rootOffset-1);
        return root;
    }
};
