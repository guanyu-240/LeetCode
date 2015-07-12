/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        TreeNode *ret = NULL;
        bool found = false;
        ret = commonAncestorHelper(root, p, q, &found);
        if (found) return ret;
        return NULL;
    }
    
    /*
    Helper function:
    Returns p if the tree only contains p
    Returns q if the tree only contains q
    Returns lowest common ancestor if the tree contains both p and q
    Returns NULL if the tree contains none of them
    */
    TreeNode* commonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q, bool *found) {
        if (root == NULL) return NULL;
        bool foundLeft=false, foundRight=false;
        TreeNode *leftRes = NULL,*rightRes = NULL;
        leftRes = commonAncestorHelper(root->left, p, q, &foundLeft);
        if (foundLeft) {                               // already found in left sub-tree
            *found = true;
            return leftRes;
        }
        if ((root == p && leftRes == q) ||
            (root == q && leftRes == p)) {             // one is the ancestor of the other
            *found = true;
            return root;
        }

        rightRes = commonAncestorHelper(root->right, p, q, &foundRight);
        if (foundRight) {                              // already found in right sub-tree
            *found = true;
            return rightRes;
        }
        if ((root == p && rightRes == q) ||
            (root == q && rightRes == p)) {            // one is the ancestor of the other
            *found = true;
            return root;
        }
                                                
        if ((leftRes == p && rightRes == q) ||
            (leftRes == q && rightRes == p)) {         // p and q reside in different sides
            *found = true;
            return root;
        }
        if (root == p || root == q) {                  // root is p or q, nth found in left or right
            if (p == q) *found = true;                 // special case for p and q are the same node
            return root;
        }
        if (leftRes != NULL) return leftRes;           // found one of them in the left sub-tree
        if (rightRes != NULL) return rightRes;         // found one of them in the right sub-tree
        return NULL;
    }
};
