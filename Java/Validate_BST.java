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
    public boolean isValidBST(TreeNode root) {
        return checkBST(root, (long)Integer.MIN_VALUE, (long)Integer.MAX_VALUE);
    }
    
    private boolean checkBST(TreeNode root, long leftBound, long rightBound) {
        if (root == null) return true;
        if (root.val < leftBound || root.val > rightBound) return false;
        if (!checkBST(root.left, leftBound, (long)root.val-1)) return false;
        if (!checkBST(root.right, (long)root.val+1, rightBound)) return false;
        return true;
    }
}
