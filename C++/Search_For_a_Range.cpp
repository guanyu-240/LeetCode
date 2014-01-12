class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int left = 0, right = n - 1;
        int start, end;
        vector<int> ret;
        ret.push_back(-1); ret.push_back(-1); 
        bool found = false;
        while (left <= right){
            start = (left + right) / 2;
            if (A[start] < target) left = start + 1;
            else if (A[start] > target) right = start - 1;
            else if (start == 0 || (start != 0 && A[start-1] < target)){
                found = true;
                break;
            }
            else right = start - 1;
        }
        if (!found) return ret;
        ret[0] = start;
        left = 0; right = n-1;
        while (left <= right){
            end = (left + right) / 2;
            if (A[end] < target)left = end + 1;
            else if (A[end] > target) right = end - 1;
            else if (end == n - 1 || (end != n - 1 && A[end+1] > target)) break;
            else left = end + 1;
        }
        ret[1] = end;
        return ret;
    }
};
