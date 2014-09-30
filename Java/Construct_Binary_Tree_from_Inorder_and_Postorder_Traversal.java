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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return buildTreeRecursively(inorder, 0, postorder, 0, inorder.length);
    }
    private TreeNode buildTreeRecursively(int[] inorder, int startI, int[] postorder, int startP, int n){
        if (n == 0) return null;
        TreeNode ret = new TreeNode(postorder[startP+n-1]);
        int offset = 0;
        while (offset < n) {
            if (inorder[startI+offset] == postorder[startP+n-1]) break;
            offset ++;
        }
        ret.left = buildTreeRecursively(inorder, startI, postorder, startP, offset);
        ret.right = buildTreeRecursively(inorder, startI+offset+1, postorder, startP+offset, n-offset-1);
        return ret;
    }
}
