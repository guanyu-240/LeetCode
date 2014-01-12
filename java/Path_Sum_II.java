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
    private ArrayList<ArrayList<Integer>> ret;
    public ArrayList<ArrayList<Integer>> pathSum(TreeNode root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ret = new ArrayList<ArrayList<Integer>>();
        if (root == null) return ret;
        solve (new ArrayList<Integer>(), root, sum);
        return ret;
    }
    
    public void solve(ArrayList<Integer> path, TreeNode root, int sum){
        if (root == null) return;
        ArrayList<Integer> newPath = new ArrayList<Integer>(path);
        newPath.add(root.val);
        sum -= root.val;
        if (root.left == null && root.right == null) {
            if (sum == 0) {
                ret.add(newPath);
            }
            else {
                return;
            }
        }
        solve(newPath, root.left, sum);
        solve(newPath, root.right, sum);
        
    }
}
