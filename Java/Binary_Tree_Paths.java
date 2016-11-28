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
    List<String> ret;
    public List<String> binaryTreePaths(TreeNode root) {
        ret = new LinkedList<String>();
        StringBuilder pred = new StringBuilder();
        if (root == null) return ret;
        solve(root, pred);
        return ret;
    }
    private void solve(TreeNode root, StringBuilder pred) {
        int count_added = 0;
        if (pred.length() > 0) {
            pred.append("->");
            count_added = 2;
        }
        pred.append(root.val);
        count_added += Integer.toString(root.val).length();
        if (root.left == null && root.right == null) {
            ret.add(pred.toString());
        }
        if (root.left != null) {
            solve(root.left, pred);
        }
        if (root.right != null){
            solve(root.right, pred);
        }
        pred.setLength(pred.length()-count_added);
    }
}
