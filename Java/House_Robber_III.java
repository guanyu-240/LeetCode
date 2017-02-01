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
    private int[] robCalc(TreeNode root) {
        int[] ret = new int[]{0, 0};
        if (root == null) return ret;
        int[] left = robCalc(root.left), right = robCalc(root.right);
        ret[0] = root.val + left[1] + right[1];
        ret[1] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        return ret;
    }
    public int rob(TreeNode root) {
        int[] cands = robCalc(root);
        return Math.max(cands[0], cands[1]);
    }
}
