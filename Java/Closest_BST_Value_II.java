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
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        Stack<TreeNode> predecessor = new Stack<TreeNode> ();
        Stack<TreeNode> successor = new Stack<TreeNode> ();
        List<Integer> ret = new LinkedList<Integer>();
        
        while (root != null) {
            if (root.val < target) {
                predecessor.push(root);
                root = root.right;
            }
            else {
                successor.push(root);
                root = root.left;
            }
        }
        
        boolean whichToPop = true;
        TreeNode tmp;
        while (k > 0 && (!predecessor.isEmpty() || !successor.isEmpty())) {
            if (predecessor.isEmpty()) whichToPop = false;
            else if (successor.isEmpty()) whichToPop = true;
            else {
                whichToPop = (predecessor.peek().val+successor.peek().val > 2*target ?
                                true : false);
            }
            if (whichToPop) {
                tmp = predecessor.pop();
                ret.add(tmp.val);
                tmp = tmp.left;
                while (tmp != null) {
                    predecessor.push(tmp);
                    tmp = tmp.right;
                }
            }
            else {
                tmp = successor.pop();
                ret.add(tmp.val);
                tmp = tmp.right;
                while (tmp != null) {
                    successor.push(tmp);
                    tmp = tmp.left;
                }
            }
            k --;
        }
        return ret;
    }
}
