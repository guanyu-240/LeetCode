ass Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        int lenlist = L.size();
        if (lenlist == 0) {
            return ret;
        }
        int strsize = L[0].length();
        int lenstr = S.length();
        map<string, int> dict, appear;
        map<string, int>::iterator it1, it2;
        for (int n = 0; n < lenlist; n ++){
            ++ dict[L[n]];
        }
        int end = lenstr - strsize * lenlist;
        string tmp;
        int n,i;
        for (n = 0; n <= end; n ++) {
            appear.clear();
            int endI = n + strsize * (lenlist - 1);
            for (i = n; i <= endI; i += strsize){
                tmp = S.substr(i, strsize);
                it1 = dict.find(tmp);
                if (it1 == dict.end() || ++appear[tmp] > it1->second){
                    break;
                }
            }
            if (i > endI){
                ret.push_back(n);
            }
        }
        return ret;
    }
};
