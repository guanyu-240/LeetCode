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
    Originally, keep a variable 'remain' for recording the number of nodes not yet 
    visited for each level, decrement by 1 when visit a node. When it comes to 0,
    the number of nodes in the queue is the number of nodes in the next level.
    If 'remain' ara assigned a wrong value, the whole result will be wrong.
    */
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode *> nodesQueue;
        vector<vector<int>> ret;
        ret.clear();
        if (root == NULL){
            return ret;
        }
        nodesQueue.push(root);
        int remain = 1; // number of nodes remain per level
        vector<int>vals;
        while (!nodesQueue.empty()){
            remain --;
            TreeNode *node = nodesQueue.front();
            nodesQueue.pop();
            vals.push_back(node->val);
            if (node->left != NULL){
                nodesQueue.push(node->left);
            }
            if (node->right != NULL){
                nodesQueue.push(node->right);
            }
            if (remain == 0){
                vector<int> tmp(vals);
                ret.push_back(tmp);
                vals.clear();
                remain = nodesQueue.size();
            }
        }
        return ret;
    }
};
