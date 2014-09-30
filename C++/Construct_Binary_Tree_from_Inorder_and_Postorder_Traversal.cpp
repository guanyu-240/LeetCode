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
private:
    TreeNode *buildTreeRecursively(vector<int> &inorder, int startI, 
                                   vector<int> &postorder, int startP, int n) {
        if (n == 0) return NULL;
        TreeNode *ret = new TreeNode(postorder[startP+n-1]);
        int offset = 0;
        while (offset < n) {
            if (inorder[startI+offset] == postorder[startP+n-1]) break;
            offset ++;
        }
        ret->left = buildTreeRecursively(inorder, startI, postorder, startP, offset);
        ret->right = buildTreeRecursively(inorder, startI+offset+1, postorder, startP+offset, n-offset-1);
        return ret;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeRecursively(inorder, 0, postorder, 0, inorder.size());
    }
};
