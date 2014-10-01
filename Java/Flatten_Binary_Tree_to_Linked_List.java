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
    /*
    Pre-order flatten method
    */
    private TreeNode lastVisited;
    public void flatten(TreeNode root) {
        if (root == null) return;
        lastVisited = root;
        if (root.left == null && root.right == null) return;
        TreeNode rightTree = root.right;
        if (root.left != null) {
            flatten(root.left);
            root.right = root.left;
            root.left = null;
            lastVisited.right = rightTree;
        }
        if (rightTree != null) {
            flatten(rightTree);
        }
    } 
}
