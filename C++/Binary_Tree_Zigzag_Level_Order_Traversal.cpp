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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        queue<TreeNode *> nodesQueue;
        vector<vector<int>> ret;
        ret.clear();
        if (root == NULL){
            return ret;
        }
        nodesQueue.push(root);
        int remain = 1; // number of nodes remain per level
        vector<int>vals;
        int level = 1;
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
                if (level % 2 == 0) {
                    reverse(tmp.begin(), tmp.end());
                }
                ret.push_back(tmp);
                vals.clear();
                remain = nodesQueue.size();
                level ++;
            }
        }
        return ret;
    }
};
