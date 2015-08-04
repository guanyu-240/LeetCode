class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int boundLeft = -1;
        int boundRight = n;
        int i = 0;
        while (i < boundRight){
            if (nums[i] == 0){
                boundLeft ++;
                nums[i] = nums[boundLeft];
                nums[boundLeft] = 0;
                if (i == boundLeft){i ++;}
            }
            else if (nums[i] == 2){
                boundRight --;
                nums[i] = nums[boundRight];
                nums[boundRight] = 2;
            }
            else {
                i ++;
            }
        }
    }
};
