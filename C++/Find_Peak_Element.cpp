class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if (num.size() == 0) return -1;
        return search(num, 0, num.size()-1);
    }
    int search(const vector<int> &num, int left, int right){
        if (left == right) return left;
        if (left+1 == right) {
            return (num[left] > num[right] ? left : right);
        }
        int mid = (left + right)/2;
        if (num[mid] < num[mid-1]) right = mid - 1; // left half has a guaranteed peak
        else left = mid;                            // right half has a guaranteed peak
        search(num, left, right);
    }
};
