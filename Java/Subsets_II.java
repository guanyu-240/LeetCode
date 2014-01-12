public class Solution {
    /*
    Recursion Function:
    For a existing subset s, there are k distinct unselected numbers.
    Generate k new different subsets by copying s and append a candidate number.
    For every new subset, call recursion function if this subset can generate new subsets.
    */
    ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
    public ArrayList<ArrayList<Integer>> subsetsWithDup(int[] num) {
        ret.clear();
        Arrays.sort(num);
        ArrayList<Integer> cand = new ArrayList<Integer>();
        ret.add(cand);
        solve(cand, num, 0);
        return ret;
    }
    
    private void solve (ArrayList<Integer> cand, int[] num, int start) {
        for (int i = start; i < num.length; i ++) {
            if (i == start || (i > start && num[i] != num[i-1])){
                ArrayList<Integer> newCand = new ArrayList<Integer> (cand);
                newCand.add(num[i]);
                ret.add(newCand);
                if (i < num.length - 1) {
                    solve (newCand, num, i+1);
                }
            }
        }
    }
}
