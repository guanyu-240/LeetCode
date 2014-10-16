class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        if (n == 0) return 0;
        int left = 0, right = n-1, mid = 0;
        while (left <= right) {
            if (left == right) return num[left];
            mid = (left + right)/2;
            if (num[left] < num[mid]) {
                if (num[left] < num[right]) return num[left];
                else left = mid + 1;
            }
            else if (left == mid) return min(num[left], num[right]);
            else right = mid;
        }
        return 0;
    }
};
