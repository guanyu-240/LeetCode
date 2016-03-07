/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        TreeNode ret = null;
        while (root != null) {
            if (root.val > p.val) {
                ret = root;
                root = root.left;
            }
            else {
                root = root.right;
            }
        }
        return ret;
    }
}
