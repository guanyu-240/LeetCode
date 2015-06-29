class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        Using Boyer-Moore Majority Voting Algorithm
        Iterate through the array and track the most voted 
        element.
        */
        if (nums.size() == 0) return 0;
        int vote = 0, count = 0;
        for (int x : nums) {
            if (count == 0) {
                vote = x;
                count ++;
            }
            else if (vote == x) {
                count ++;
            }
            else {
                count --;
            }
        }
        return vote;
    }
};
