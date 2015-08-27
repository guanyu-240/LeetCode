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
    public int closestValue(TreeNode root, double target) {
        double lb = (double)Integer.MIN_VALUE - 1;
        double ub = (double)Integer.MAX_VALUE + 1;
        while (root != null) {
            if (root.val < target) {
                lb = root.val;
                root = root.right;
            }
            else {
                ub = root.val;
                root = root.left;
            }
        }
        if (lb == (double)Integer.MIN_VALUE - 1) return (int)ub;
        else if (ub == (double)Integer.MAX_VALUE + 1) return (int)lb;
        else if (ub - target < target - lb) return (int)ub;
        else return (int)lb;
    }
}
