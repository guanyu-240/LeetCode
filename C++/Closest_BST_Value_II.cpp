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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> predecessor;
        stack<TreeNode*> successor;
        bool pop;
        while (root != NULL) {
            if (root->val > target) {
                successor.push(root);
                root = root->left;
            }
            else {
                predecessor.push(root);
                root = root->right;
            }
        }
        
        vector<int> ret;
        TreeNode *tmp = NULL;
        while (ret.size() < k && (!predecessor.empty() || !successor.empty())) {
            if (predecessor.empty()) pop = false;
            else if (successor.empty()) pop = true;
            else {
                if (target - predecessor.top()->val < successor.top()->val - target) {
                    pop = true;
                }
                else {
                    pop = false;
                }
            }
            if (pop) {
                tmp = predecessor.top();
                predecessor.pop();
                ret.push_back(tmp->val);
                tmp = tmp->left;
                while (tmp != NULL) {
                    predecessor.push(tmp);
                    tmp = tmp->right;
                }
            }
            else {
                tmp = successor.top();
                successor.pop();
                ret.push_back(tmp->val);
                tmp = tmp->right;
                while (tmp != NULL) {
                    successor.push(tmp);
                    tmp = tmp->left;
                }
            }
        }
        return ret;
    }
};
