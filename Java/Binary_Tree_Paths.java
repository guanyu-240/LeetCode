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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ret = new ArrayList<String>();
        if (root == null) return ret;
        ret = binaryTreePaths(root.left);
        ret.addAll(binaryTreePaths(root.right));
        if (ret.size() == 0) {
            ret.add(Integer.toString(root.val));
        }
        else {
            for (int i = 0; i < ret.size(); i++) {
                ((ArrayList<String>)ret).set(i, 
                    root.val+"->"+((ArrayList<String>)ret).get(i));
            }
        }
        return ret;
    }
}
