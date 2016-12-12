class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        int min = INT_MAX, second_min = INT_MAX;
        for (int x : nums) {
            if (x > second_min) return true; // no need to care if min is after second_min!!
            else if (x > min && x <= second_min){
                second_min = x;
            }
            else {
                min = x;
            }
        }
        return false;
    }
};
