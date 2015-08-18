public class Solution {
    public boolean validTree(int n, int[][] edges) {
        if (edges.length != n-1) return false;
        
        HashSet<Integer>[] adj_table = new HashSet[n];
        boolean[] visited = new boolean[n];
        
        for (int v = 0; v < n; v++) { adj_table[v] = new HashSet<Integer>(); }
        /* Can not use 
           Arrays.fill(adj_table, new HashSet<Integer>());
           Because only one HashSet is initialized. */
        Arrays.fill(visited, false);
        for (int[] e : edges) {
            adj_table[e[0]].add(e[1]);
            adj_table[e[1]].add(e[0]);
        }
        
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(0);
        int cur = 0;
        while (!q.isEmpty()) {
            cur = q.poll();
            if (visited[cur]) return false;
            visited[cur] = true;
            for (int v : adj_table[cur]) {
                q.add(v);
                adj_table[v].remove(cur);
            }
        }
        for (boolean isVisited : visited) {
            if (!isVisited) return false;
        }
        return true;
    }
}
