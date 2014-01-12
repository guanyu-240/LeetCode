/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    private int maxEndCurNode;
    private int maxPathValue;
    private int maxSub;
    public int maxPathSum(TreeNode root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        maxPathValue = Integer.MIN_VALUE;
        maxEndHere(root);
        return maxPathValue;
    }
    public int maxEndHere(TreeNode root) {
        if (root == null) return 0;
        int maxLeftSub = maxEndHere(root.left);
        int maxRightSub = maxEndHere(root.right);
        maxSub = Math.max(maxLeftSub, maxRightSub);
        maxEndCurNode = Math.max(maxSub+root.val, root.val);
        maxPathValue = Math.max(Math.max(maxPathValue, maxEndCurNode), maxLeftSub+maxRightSub+root.val);
        return maxEndCurNode;
    }
}
