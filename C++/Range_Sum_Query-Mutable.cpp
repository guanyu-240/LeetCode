class NumArray {
/* Using Binary Indexed Tree 
 * Reference: http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
 */
private:
    int *ft;
    vector<int> arr;
    int n;
    void update(int i, int val, bool init){
        int change = init ? val : val - arr[i];
        if (!init) arr[i] = val;
        i += 1;
        while (i <= n) {
            ft[i] += change;
            i += i & (-i);
        }
    }
public:
    NumArray(vector<int> &nums) {
        arr = nums;
        n = nums.size();
        ft = new int[n+1];
        for (int i = 0; i <= n; ++i) { ft[i] = 0;}
        for (int i = 0; i < n; ++ i) { update(i, nums[i], true); }
    }

    void update(int i, int val) {
        update(i, val, false);
    }

    int getSum(int i) {
        int ret = 0;
        i += 1;
        while (i > 0) {
            ret += ft[i];
            i -= i & (-i);
        }
        return ret;
    }
    int sumRange(int i, int j) {
        return getSum(j) - (i==0 ? 0 : getSum(i-1));
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
