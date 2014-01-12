/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
    Idea:
    For every level, the current level is already populated.
    BFS to get the nodes of the next level and connect these nodes
    */
    void connect(TreeLinkNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        TreeLinkNode *cur = NULL, *newRoot = root;
        root = NULL;
        while (newRoot != NULL || root != NULL) { // BFS termination: current level ends and next level empty
            if (root == NULL) { // current level ends
                root = newRoot;
                newRoot = NULL;
            }
            if (root->left != NULL) {
                if (newRoot == NULL) newRoot = root->left;
                else cur->next = root->left;
                cur = root->left;
            }
            if (root->right != NULL) {
                if (newRoot == NULL) newRoot = root->right;
                else cur->next = root->right;
                cur = root->right;
            }
            root = root->next;
        }
    }
};
