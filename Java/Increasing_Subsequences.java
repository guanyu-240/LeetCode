public class Solution {
    public void solve(List<List<Integer>> ret, LinkedList<Integer> cand, int[] nums, int start) {
        if (cand.size() >= 2) {
            ret.add(new LinkedList<Integer>(cand));
        }
        if (start >= nums.length) {
            return;
        }
        HashSet<Integer> used = new HashSet<Integer>();
        for (int i = start; i < nums.length; ++i) {
            if ((cand.size() == 0 || cand.peekLast() <= nums[i]) && 
                    !used.contains(nums[i])) {
                used.add(nums[i]);
                cand.add(nums[i]);
                solve(ret, cand, nums, i+1);
                cand.removeLast();
            }
        }
    }
    public List<List<Integer>> findSubsequences(int[] nums) {
        List<List<Integer>> ret = new LinkedList<List<Integer>>();
        LinkedList<Integer> cand = new LinkedList<Integer>();
        solve(ret, cand, nums, 0);
        return ret;
    }
    
}
