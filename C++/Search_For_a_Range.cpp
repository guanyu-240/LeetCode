class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int start, end;
        vector<int> ret;
        ret.push_back(-1); ret.push_back(-1); 
        bool found = false;
        while (left <= right){
            start = (left + right) / 2;
            if (nums[start] < target) left = start + 1;
            else if (nums[start] > target) right = start - 1;
            else if (start == 0 || (start != 0 && nums[start-1] < target)){
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
            if (nums[end] < target)left = end + 1;
            else if (nums[end] > target) right = end - 1;
            else if (end == n - 1 || (end != n - 1 && nums[end+1] > target)) break;
            else left = end + 1;
        }
        ret[1] = end;
        return ret;
    }
};

