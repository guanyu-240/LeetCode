/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() <= 1) return intervals.size();
        sort(intervals.begin(), intervals.end(),
            [](const Interval &x, const Interval &y) {
                return x.start < y.start;
            });
        int heap[intervals.size()+1];
        int n = 0;
        for (Interval &i : intervals) {
            if (n > 0 && i.start >= heap[0]) {
                heap[0] = i.end;
                minHeapify(heap, 0, n);
            }
            else {
                heapInsert(heap, n, i.end);
                n ++;
            }
        }
        return n;
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
            tmp = heap[i];
            heap[i] = heap[min_idx];
            heap[min_idx] = tmp;
            i = min_idx;
        }
    }
    void heapInsert(int heap[], int n, int x) {
        heap[n] = x;
        int parent, tmp;
        while (n >= 0) {
            parent = (n%2==0 ? n/2-1 : n/2);
            if (parent >= 0 && heap[n] < heap[parent]) {
                tmp = heap[n];
                heap[n] = heap[parent];
                heap[parent] = tmp;
                n = parent;
            }
            else {
                break;
            }
        }
    }
};
