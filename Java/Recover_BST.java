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
    private TreeNode wrongNode1;
    private TreeNode wrongNode2;
    private TreeNode visited;
    public void recoverTree(TreeNode root) {
        wrongNode1 = null;
        wrongNode2 = null;
        visited = null;
        discoverWrong(root);
        if (wrongNode2 == null) wrongNode2 = visited;
        if (wrongNode1 != null && wrongNode2 != null) {
            int tmp = wrongNode2.val;
            wrongNode2.val = wrongNode1.val;
            wrongNode1.val = tmp;
        }
    }
    private void discoverWrong(TreeNode root) {
        if (root == null) return;
        discoverWrong(root.left);
        if (wrongNode1 == null && visited != null && root.val < visited.val) {
            wrongNode1 = visited;
        }
        if (wrongNode1 != null && visited.val < wrongNode1.val && root.val >= wrongNode1.val) {
            wrongNode2 = visited;
        }
        visited = root;
        discoverWrong(root.right);
    }
}
