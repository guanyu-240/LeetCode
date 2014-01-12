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
    public ArrayList<Integer> postorderTraversal(TreeNode root) {
        ArrayList<Integer> ret = new ArrayList<Integer>();
        Stack<TreeNode> st = new Stack<TreeNode>();
        if (root == null) return ret;
        st.push(root);
        TreeNode node = null;
        while (!st.isEmpty()) {
            node = st.pop();
            ret.add(0, node.val);
            if (node.left != null) st.push(node.left);
            if (node.right != null) st.push(node.right);
        }
        return ret;
    }
}
