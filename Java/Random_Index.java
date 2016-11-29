public class Solution {
    private HashMap<Integer, List<Integer>> map;
    List<Integer> idx_list;
    Random rand = new Random();
    public Solution(int[] nums) {
        map = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            idx_list = map.get(nums[i]);
            if (idx_list == null) {
                idx_list = new ArrayList<Integer>();
                map.put(nums[i], idx_list);
            }
            idx_list.add(i);
        }
    }
    
    public int pick(int target) {
        idx_list = map.get(target);
        if (idx_list == null) return -1;
        return idx_list.get(rand.nextInt(idx_list.size()));
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
