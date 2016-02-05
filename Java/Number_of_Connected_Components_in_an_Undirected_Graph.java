public class Solution {
    public int countComponents(int n, int[][] edges) {
        int[] root = new int[n];
        for (int v = 0; v < n; ++ v) { root[v] = v; }
        int r1 = -1, r2 = -1;
        int ret = n;
        for (int[] e : edges) {
            r1 = find(root, e[0]);
            r2 = find(root, e[1]);
            if (r1 != r2) {
                root[r2] = r1;
                ret --;
            }
        }
        return ret;
    }
    private int find(int[] root, int x) {
        while (root[x] != x) { x = root[x]; }
        return x;
    }
}
