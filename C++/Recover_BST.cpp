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
    TreeNode *wrongNode1;
    TreeNode *wrongNode2;
    TreeNode *visited;
    void discoverWrong(TreeNode *root) {
        if (root == NULL) return;
        discoverWrong(root->left);
        if (wrongNode1 == NULL && visited != NULL && visited->val > root->val) {
            wrongNode1 = visited;
        }
        if (wrongNode1 != NULL && visited->val < wrongNode1->val && root->val >= wrongNode1->val) {
            wrongNode2 = visited;
        }
        visited = root;
        discoverWrong(root->right);
    }

public:
    void recoverTree(TreeNode *root) {
        wrongNode1 = NULL;
        wrongNode2 = NULL;
        visited = NULL;
        discoverWrong(root);
        if (wrongNode2 == NULL) wrongNode2 = visited;
        if (wrongNode1 != NULL && wrongNode2 != NULL) {
            int tmp = wrongNode2->val;
            wrongNode2->val = wrongNode1->val;
            wrongNode1->val = tmp;
        }
    }
};
