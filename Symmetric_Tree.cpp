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
    Idea:
    In-order traverse and store the result in the vector.
    Finally find whether the elements in the vector is symmetric
    */
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL){
            return true;
        }
        vector<int> traverseRes;
        traverseRes.clear();
        inOrderTraverse(root, traverseRes);
        int len = traverseRes.size();
        if (len % 2 == 0){
            return false;
        }
        int n;
        for (n = 0; n < len/2; n ++){
            if (traverseRes[n] != traverseRes[len - 1 - n]){
                return false;
            }
        }
        return true;
    }
    void inOrderTraverse(TreeNode *root, vector<int> &traverseRes){
        if (root == NULL) {
            return;
        }
        inOrderTraverse(root->left, traverseRes);
        traverseRes.push_back(root->val);
        inOrderTraverse(root->right, traverseRes);
    }
};
