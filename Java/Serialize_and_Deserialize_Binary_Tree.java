/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    private int idx;
    private String[] dataList;
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) return "x";
        return Integer.toString(root.val) + "," + 
                    serialize(root.left) + "," +
                    serialize(root.right);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        dataList = data.split(",");
        idx = 0;
        return deserialize();
    }
    
    private TreeNode deserialize() {
        TreeNode ret = null;
        if (!dataList[idx++].equals("x")) {
            ret = new TreeNode(Integer.parseInt(dataList[idx-1]));
            ret.left = deserialize();
            ret.right = deserialize();
        }
        return ret;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
