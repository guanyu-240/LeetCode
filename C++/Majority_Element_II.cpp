class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        if (n == 0) return ret;
        int cand1=0,cand2=0,vote1=0,vote2=0,c1=0,c2 = 0;
        for (int x : nums) {
            if (vote1 == 0) { cand1 = x; vote1 ++; }
            else if (vote2 == 0) { cand2 = x; vote2 ++; }
            else if (cand1 == x) { vote1 ++; }
            else if (cand2 == x) { vote2 ++; }
            else {
                vote1 --;
                vote2 --;
            }
        }
        for (int x : nums) {
            if (x == cand1 && vote1 > 0) c1 ++;
            else if (x == cand2 && vote2 > 0) c2 ++;
        }
        if (c1 > n/3) ret.push_back(cand1);
        if (c2 > n/3) ret.push_back(cand2);
        return ret;
    }
};
