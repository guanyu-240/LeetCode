/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    int idx;
    string data;
    
    TreeNode* deserialize() {
        TreeNode *ret = NULL;
        if (data[idx] == ',') idx ++;
        if (data[idx] != 'x') {
            int val = 0;
            bool neg = false;
            while (idx < data.length() && data[idx++] != ',') {
                if (data[idx-1] == '-') neg = true;
                else val = val*10 + (data[idx-1] - '0');
            }
            if (neg) val *= -1;
            ret = new TreeNode(val);
            ret->left = deserialize();
            ret->right = deserialize();
        }
        else {
            idx += 2;
        }
        return ret;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "x";
        return to_string(root->val) + "," + 
                serialize(root->left) + "," +
                serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        this->data = data;
        idx = 0;
        return deserialize();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
