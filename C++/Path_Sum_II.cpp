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
    vector<vector <int>> ret;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL){
            return ret;
        }
        vector<int> cand;
        ret.clear();
        cand.clear();
        solve(root, cand, sum);
        return ret;
    }
    void solve(TreeNode *root, vector<int> &cand, int sum){
        int sum_new = sum - root -> val;
        vector<int> cand_new(cand);
        cand_new.push_back(root -> val);
        if (root -> left == NULL && root -> right == NULL){
            if (sum_new == 0){
                ret.push_back(cand_new);
                return;
            }
            return;
        }
        if (root -> left != NULL) {
            solve(root -> left, cand_new, sum_new);
        }
        if (root -> right != NULL) {
            solve(root -> right, cand_new, sum_new);
        }
    }
};
