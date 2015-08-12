public class Solution {
    public List<List<Integer>> getFactors(int n) {
        return solve(n, 2);
    }
    private List<List<Integer>> solve(int n, int start) {
        List<List<Integer>> ret = new LinkedList<List<Integer>>();
        for (int x = start; x <= Math.sqrt(n); x ++) {
            if (n%x == 0) {
                ret.add(new LinkedList<Integer>(Arrays.asList(x, n/x)));
                List<List<Integer>> tmp = solve(n/x, x);
                for (List<Integer> cand : tmp) {
                    ((LinkedList<Integer>)cand).addFirst(x);
                    ret.add(cand);
                }
            }
        }
        return ret;
    }
}
