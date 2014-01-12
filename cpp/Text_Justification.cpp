class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = words.size();
        int start = 0, end = -1, maxSpaces = -1, spacesCurLine = 0;
        int strLen = 0;
        vector<string> ret;
        for (int n = 0; n < len; n ++) {
            strLen += words[n].length();
            maxSpaces += 1;
            if (strLen + maxSpaces > L) {
                strLen -= words[n].length();
                end = n - 1;
                spacesCurLine = L - strLen;
                string newStr = genString(words, start, end, spacesCurLine, L, false);
                ret.push_back(newStr);
                start = n;
                strLen = words[n].length();
                maxSpaces = 0;
            }
        }
        if (end != len - 1) {
            spacesCurLine = L - strLen;
            string newStr = genString(words, start, len-1, spacesCurLine, L, true);
            ret.push_back(newStr);
        }
        return ret;
    }
    string genString(vector<string> &words, int start, int end, int totalSpaces, int L, bool lastline){
        string ret("");
        ret.append(words[start]);
        if (start == end) {
            if (totalSpaces > 0)
                ret.append(totalSpaces, ' ');
            return ret;
        }
        int numSpaces = lastline ? 1 : totalSpaces/(end - start);
        int remain = lastline ? 0 : totalSpaces % (end - start);
        for (int n = start + 1; n <= end; n ++) {
            if (remain > 0) {
                ret.append((numSpaces + 1), ' ');
                remain --;
            }
            else {
                ret.append(numSpaces, ' ');
            }
            ret.append(words[n]);
        }
        if (lastline && ret.length() < L){
            ret.append(L-ret.length(), ' ');
        }
        return ret;
    }
};
