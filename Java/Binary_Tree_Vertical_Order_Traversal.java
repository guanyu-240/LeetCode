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
    public List<List<Integer>> verticalOrder(TreeNode root) {
        ArrayList<ArrayList<Integer>>[] orders = new ArrayList[]{
                new ArrayList<ArrayList<Integer>>(),
                new ArrayList<ArrayList<Integer>>()
        };

        Queue<TreeNode> nodes = new LinkedList<TreeNode>();
        Queue<Integer> colIds = new LinkedList<Integer>();
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        if (root == null) return ret;
        
        TreeNode node = null;
        int colId = 0;
        nodes.add(root);
        colIds.add(0);
        
        int count = 1;
        int x = 0, y = 0;
        int i = 0;
        while (nodes.size() > 0) {
            count --;
            node = nodes.poll();
            colId = colIds.poll();
            x = colId < 0 ? 0 : 1;
            y = colId < 0 ? -colId-1 : colId;
            if (orders[x].size() <= y) {
                i = orders[x].size();
                while (i++ <= y) orders[x].add(new ArrayList<Integer>());
            }
            orders[x].get(y).add(node.val);
            
            if (node.left != null) {
                nodes.add(node.left);
                colIds.add(colId-1);
            }
            if (node.right != null) {
                nodes.add(node.right);
                colIds.add(colId+1);
            }
            if (count == 0) count = nodes.size();
        }
        
        for (i = orders[0].size()-1; i >= 0; --i) {
            if (orders[0].get(i).size() > 0) ret.add(orders[0].get(i));
        }
        for (i = 0; i < orders[1].size(); ++i) {
            if (orders[1].get(i).size() > 0) ret.add(orders[1].get(i));
        }
        return ret;
    }
}
