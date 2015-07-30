class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        /*
        Bucket sort strategy, each bucket has the size of t,
        the bucket index of a number x is floor(x/t)
        For each number x, the candidate y(y<x) can only be in
        the same bucket as x or the two neighboring buckets
        */
        if (t < 0) return false;
        if (k <= 0) return false;
        unordered_map<int, int> buckets;
        unordered_map<int, int>::iterator it;
        int n = nums.size();
        int key = 0, candIdx=0;
        for (int i = 0; i < n; i ++) {
            key = nums[i]/max(1, t);
            for (int x = key-1; x <= key+1; x++) {
                it = buckets.find(x);
                if (it != buckets.end()) {
                    candIdx = it->second;
                    if (i-candIdx <= k && 
                            abs((long long)nums[i]-(long long)nums[candIdx]) <= t) {
                        return true;
                    }
                }
            }
            buckets[key] = i;
        }
        return false;
    }
};
