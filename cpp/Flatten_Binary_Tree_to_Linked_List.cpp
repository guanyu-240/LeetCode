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
    TreeNode *visited;
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;
        solve(root);
    }
    void solve(TreeNode *root){
        visited = root;
        if (root->left == NULL && root->right == NULL) return;
        if (root->left != NULL){                // flatten the left side
            solve(root->left);
            visited->right = root->right;
            root->right = root->left;           // move the flattered left tree to the right
            root->left = NULL;
        }
        if (visited->right != NULL){            // flatten the right sight
            solve(visited->right);
        }
    }
};
