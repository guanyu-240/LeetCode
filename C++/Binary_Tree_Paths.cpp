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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == NULL) return ret;
        ret = binaryTreePaths(root->left);
        vector<string>tmp = binaryTreePaths(root->right);
        ret.insert(ret.end(), tmp.begin(), tmp.end());
        if (ret.size() == 0) ret.push_back(to_string(root->val));
        else {
            for (string &s : ret) {
                s = to_string(root->val) + "->" + s;
            }
        }
        return ret;
    }
};
