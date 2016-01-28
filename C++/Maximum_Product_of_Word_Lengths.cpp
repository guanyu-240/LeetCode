class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if (n < 2) return 0;
        vector<int> bits(n, 0);
        int char_map = 0;
        int ret = 0;
        
        for (int i = 0; i < n; ++ i) {
            char_map = 0;
            for (int j = 0; j < words[i].length(); ++ j) {
                char_map |= (1 << (words[i][j]-'a'));
            }
            bits[i] = char_map;
        }
        
        for (int i = 0; i < n-1; ++i) {
            for (int j = i +1; j < n; ++j) {
                if ((bits[i]&bits[j]) == 0) {
                    ret = max(ret, (int)(words[i].length()*words[j].length()));
                }
            }
        }
        return ret;
    }
};
