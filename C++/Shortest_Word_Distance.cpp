class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        /*
        For each word1, find the closest word2 before it and after it
        */
        if (word1 == word2) return 0;
        int n = words.size(), ptr1 = 0, ptr2 = 0;
        int ret = n;
        while (ptr1 < n && ptr2 < n) {
            if (words[ptr1] == word1 && words[ptr2] == word2) {
                ret = min(abs(ptr2-ptr1), ret);
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
