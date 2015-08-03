class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = num.size();
        if (len == 0) {
            return 0;
        }
        unordered_set<int> num_set;
        for (int x : num) { num_set.insert(x); }
        int back,front = 0;
        int ret = 1;
        for (int x : num_set) {
            back = front = x;
            while (num_set.find(back-1) != num_set.end()) {
                back --;
                num_set.erase(back);
            }
            while (num_set.find(front+1) != num_set.end()) {
                front ++;
                num_set.erase(front);
            }
            ret = max(ret, front-back+1);
        }
        return ret;
    }
};
