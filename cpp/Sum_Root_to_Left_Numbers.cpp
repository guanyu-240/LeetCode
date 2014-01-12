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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL){
            return 0;
        }
        int sum = 0;
        solve(root, 0, sum);
        return sum;
    }
    void solve(TreeNode *root, int number, int &sum){
        int numberNew = number*10 + root->val;
        if (root->left == NULL && root->right == NULL){
            sum += numberNew;
            return;
        }
        if (root->left != NULL){
            solve(root->left, numberNew, sum);
        } 
        if (root->right != NULL){
            solve(root->right, numberNew, sum);
        }
    }
};
