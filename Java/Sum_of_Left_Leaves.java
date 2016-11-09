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
    public int sumOfLeftLeaves(TreeNode root) {
        return sumOfLeftLeavesHelper(root, false);
    }
    private int sumOfLeftLeavesHelper(TreeNode root, boolean fromLeft) {
        if (root == null) return 0;
        if (root.left == null && root.right == null && fromLeft) {
            return root.val;
        }
        return sumOfLeftLeavesHelper(root.left, true) + sumOfLeftLeavesHelper(root.right, false);
    }
}
