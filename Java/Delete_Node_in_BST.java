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
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null;
        
        TreeNode parent = null, node = root, newNode = null, newNodeParent = null;
        while (node != null && node.val != key) {
            parent = node;
            if (node.val < key) node = node.right;
            else node = node.left; 
        }
        if (node != null) {
            if (node.left == null || node.right == null) {
                // if the node is a leaf, just remove it
                // if the node has one child, replace it with the child
                newNode = node.left != null ? node.left : node.right;
                if (parent == null) root = newNode;
                else {
                    if (parent.left == node) parent.left = newNode;
                    else parent.right = newNode;
                }
            }
            else {
                // find its successor, it's successor will be either a leaf
                // or a node with only right child
                newNode = node.right;
                while (newNode.left != null) {
                    newNodeParent = newNode;
                    newNode = newNode.left; 
                }
                if (newNodeParent != null) {
                    newNodeParent.left = newNode.right;
                    newNode.right = node.right;
                }
                newNode.left = node.left;
                node.right = node.left = null;
                if (parent != null) {
                    if (node == parent.left) parent.left = newNode;
                    else parent.right = newNode;
                }
                else { root = newNode; }
            }
        }
        return root;
    }
}
