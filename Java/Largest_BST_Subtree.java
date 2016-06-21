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
    public static class TreeInfo {
        private int BSTSize;
        private int minV;
        private int maxV;
        public TreeInfo (int BSTSize, int minV, int maxV) {
            this.BSTSize = BSTSize;
            this.minV = minV;
            this.maxV = maxV;
        }
        public int getBSTSize () { return this.BSTSize; }
        public int getMinV () { return this.minV; }
        public int getMaxV () { return this.maxV; }
        public void setBSTSize(int BSTSize) { this.BSTSize = BSTSize; }
        public void setMinV (int minV) { this.minV = minV; }
        public void setMaxV (int maxV) { this.maxV = maxV; }
    }
    private int largestBSTSize;
    public int largestBSTSubtree(TreeNode root) {
        largestBSTSize = 0;
        solve(root);
        return largestBSTSize;
    }
    public TreeInfo solve(TreeNode root) {
        if (root == null) return new TreeInfo(0, 0, 0);
        TreeInfo left = solve(root.left);
        if (left.getBSTSize() == -1 || (left.getBSTSize() > 0 && left.getMaxV() >= root.val)) {
            return new TreeInfo(-1, 0, 0);
        }
        TreeInfo right = solve(root.right);
        if (right.getBSTSize() == -1 || (right.getBSTSize() > 0 && right.getMinV() <= root.val)) {
            return new TreeInfo(-1, 0, 0);
        }
        TreeInfo ret = right;
        ret.setMaxV(right.getBSTSize() > 0 ? right.getMaxV() : root.val);
        ret.setBSTSize(left.getBSTSize()+1+right.getBSTSize());
        ret.setMinV(left.getBSTSize() > 0 ? left.getMinV() : root.val);
        largestBSTSize = Math.max(largestBSTSize, ret.getBSTSize());
        return ret;
        
    }
}
