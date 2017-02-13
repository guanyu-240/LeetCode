public class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>();
        for (int x : nums) {
            if (maxHeap.size() < k) {
                maxHeap.add(x);
            } else if (x > maxHeap.peek()) {
                maxHeap.poll();
                maxHeap.add(x);
            }
        }
        return maxHeap.peek();
    }
}
