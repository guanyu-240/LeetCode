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
    TreeNode *wrongNode1;
    TreeNode *wrongNode2;
    void recoverTree(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        visited = NULL;
        wrongNode1 = NULL;
        wrongNode2 = NULL;
        discoverWrong(root);
        if (wrongNode1 != NULL && wrongNode2 != NULL) {
            int tmp = wrongNode1->val;
            wrongNode1->val = wrongNode2->val;
            wrongNode2->val = tmp;
        }
    }
    
    void discoverWrong(TreeNode *root){
        if (root == NULL) {
            return;
        }
        discoverWrong(root->left);
        if (visited != NULL && root->val < visited->val) {
            if (wrongNode1 == NULL) {
                wrongNode1 = visited;
                wrongNode2 = root;
            }
            else {
                wrongNode2 = root;
            }
        }
        visited = root;
        discoverWrong(root->right);
    }
};
