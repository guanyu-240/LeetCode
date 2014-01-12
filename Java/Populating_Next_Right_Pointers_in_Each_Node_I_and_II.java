/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    /*
    Idea:
    For every level, the current level is already populated.
    BFS to get the nodes of the next level and connect these nodes
    */
    public void connect(TreeLinkNode root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        TreeLinkNode cur = null, newRoot = root;
        root = null;
        while (newRoot != null || root != null) { // BFS Termination: current level ends and next level empty
            if (root == null) { //current level ends
                root = newRoot;
                newRoot = null;
            }
            if (root.left != null) {
                if (newRoot == null) newRoot = root.left;
                else cur.next = root.left;
                cur = root.left;
            }
            if (root.right != null) {
                if (newRoot == null) newRoot = root.right;
                else cur.next = root.right;
                cur = root.right;
            }
            root = root.next;
        }
    }
}
