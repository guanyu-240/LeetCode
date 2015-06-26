class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (k <= 0 || k > n) return INT_MIN;
        int heap[k+1];
        int tmp;
        for (int i = 0; i < n; i ++) {
            heapInsert(heap, min(i, k), nums[i]);
            if (i >= k) {
                /* extract min */
                tmp = heap[0];
                heap[0] = heap[k];
                heap[k] = tmp;
                minHeapify(heap, 0, k);
            }
        }
        return heap[0];
    }
    void minHeapify(int heap[], int i, int n) {
        int left, right, min_idx, tmp;
        while (i < n) {
            left = 2*i+1;
            right = 2*i+2;
            min_idx = i;
            if (left < n && heap[left] < heap[min_idx]) {
                min_idx = left;
            }
            if (right < n && heap[right] < heap[min_idx]) {
                min_idx = right;
            }
            if (min_idx == i) break;
            tmp = heap[min_idx];
            heap[min_idx] = tmp;
            i = min_idx;
        }
    }
    void heapInsert(int heap[], int k, int x) {
        heap[k] = x;
        int i = k;
        int parent, tmp;
        while (i >= 0) {
            parent = (i%2==0 ? i/2-1 : i/2);
            if (parent >= 0 && heap[i] < heap[parent]) {
                tmp = heap[i];
                heap[i] = heap[parent];
                heap[parent] = tmp;
                i = parent;
            }
            else {
                break;
            }
        }
    }
};
