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
    public List<List<Integer>> findLeaves(TreeNode root) {
        List<List<Integer>> ret = new ArrayList<>();
        treeDepth(ret, root);
        return ret;
    }
    private int treeDepth(List<List<Integer>> ret, TreeNode root) {
        if (root == null) return 0;
        int depth = 1 + Math.max(treeDepth(ret, root.left), treeDepth(ret, root.right));
        if (ret.size() < depth) ret.add(new ArrayList<>());
        ret.get(depth-1).add(root.val);
        return depth;
    }
}
