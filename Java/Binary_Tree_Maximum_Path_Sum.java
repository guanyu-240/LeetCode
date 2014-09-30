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
    private int maxPath;
    private int maxPathAcrossThisRoot;
    /*
    For every root, there are 4 candidate paths(across this root) for maximum path sum
    root only
    root + <max weight path ending at left child>
    root + <max weight path ending at right child>
    root + <max weight path ending at left child> + <max weight path ending at right child>
    */
    public int maxPathSum(TreeNode root) {
        maxPath = Integer.MIN_VALUE;
        maxEndThisRoot(root);
        return maxPath;
    }
    private int maxEndThisRoot(TreeNode root) {
        if (root == null) return 0;
        int maxEndL = maxEndThisRoot(root.left);
        int maxEndR = maxEndThisRoot(root.right);
        maxPathAcrossThisRoot = root.val + Math.max(maxEndL, 0) + Math.max(maxEndR, 0);
        maxPath = Math.max(maxPath, maxPathAcrossThisRoot);
        return root.val + Math.max(Math.max(maxEndL, maxEndR), 0);
    }
}
