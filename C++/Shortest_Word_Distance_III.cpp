class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int n = words.size(), ptr1 = 0, ptr2 = 0;
        int ret = n;
        while (ptr1 < n && ptr2 < n) {
            if (words[ptr1] == word1 && words[ptr2] == word2) {
                if (ptr1 != ptr2) ret = min(abs(ptr2-ptr1), ret);
                if (ret == 1) return ret;
                if (ptr1 > ptr2) ptr2 ++;
                else ptr1 ++;
            }
            else {
                if (word1 != words[ptr1]) ptr1 ++;
                if (word2 != words[ptr2]) ptr2 ++;
            }
        }
        return ret;
    }
};
