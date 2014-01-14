/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; left = null; right = null; }
 * }
 */
public class Solution {
    public ArrayList<TreeNode> generateTrees(int n) {
        return solve(1, n);
    }
    
    private ArrayList<TreeNode> solve(int left, int right) {
        ArrayList<TreeNode> ret =  new ArrayList<TreeNode>();
        if (left > right) {
            ret.add(null);
            return ret;
        }
        for (int i = left; i <= right; i ++) {
            ArrayList<TreeNode> leftTree = solve(left, i-1);
            ArrayList<TreeNode> rightTree = solve(i+1, right);
            for (TreeNode x : leftTree) {
                for (TreeNode y : rightTree) {
                    TreeNode root = new TreeNode(i);
                    root.left = x;
                    root.right = y;
                    ret.add(root);
                }
            }
        }
        return ret;
    }
}
