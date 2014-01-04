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
    /*
    preorder[start] is the root node;
    Find the subarray in preorder and inorder for root->left
    Find the subarray in preorder and inorder for root->right
    Recursively build the subtrees by passing the subarrays
    */
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return solve(preorder, 0, inorder, 0, preorder.size());
    }
    TreeNode *solve(vector<int> &preorder, int startP, vector<int> &inorder, int startI, int len){
        if (len == 0) {
            return NULL;
        }
        int rootVal = preorder[startP];
        TreeNode *root = new TreeNode(rootVal);
        int rootOffset = 0;            // the offset of root value in inorder
        for (int n = 0; n < len; n ++){
            if (inorder[startI + n] == rootVal) {
                rootOffset = n;
                break;
            }
        }
        root->left = solve(preorder, startP+1, inorder, startI, rootOffset);
        root->right =  solve(preorder, startP+1+rootOffset, inorder, startI+rootOffset+1, len-rootOffset-1);
        return root;
    }
};
