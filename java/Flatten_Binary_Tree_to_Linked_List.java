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
    private TreeNode visited;
    public void flatten(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (root == null) return;
        visited = null;
        solve (root);
    }
    private void solve(TreeNode root) {
        visited = root;
        if (root.left == null && root.right == null) return;
        if (root.left != null) {
            solve(root.left);
            visited.right = root.right;
            root.right = root.left;
            root.left = null;
        }
        if (visited.right != null) {
            solve (visited.right);
        }
    }
}
