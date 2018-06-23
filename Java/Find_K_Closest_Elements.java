class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        LinkedList<Integer> res = new LinkedList<Integer>();
        if (k > arr.length) {
            return res;
        }
        
        int left = 0, right = arr.length - 1, target = 0;
        while (left <= right) {
            target = (left + right) / 2;
            if (arr[target] == x) {
                break;
            } else if (arr[target] < x) {
                left = target + 1;
            } else {
                right = target - 1;
            }
        }
        
        if (arr[target] <= x) {
            left = target;
            right = target + 1;
        } else {
            left = target - 1;
            right = target;
        }
        
        while (res.size() < k) {
            if (right >= arr.length || (left >= 0 && x - arr[left] <= arr[right] - x)) {
                res.addFirst(arr[left--]);
            } else {
                res.addLast(arr[right++]);
            }
        }
        
        return res;
    }
}
