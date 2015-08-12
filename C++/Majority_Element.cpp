class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        Using Boyer-Moore Majority Voting Algorithm
        Iterate through the array and track the most voted 
        element.
        Proof of Boyer-Moore Voting Algorithm:
        Assume the majority element x exists in array A.
        For any number i in the array A, the vote of i
        would reach 0 when every i is paired with other
        numbers, then i can not be majority
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
