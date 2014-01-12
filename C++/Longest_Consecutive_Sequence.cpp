class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = num.size();
        if (len == 0) {
            return 0;
        }
        int ret = 0;
        unordered_map<int, int> seq_index;
        unordered_map<int, int>::iterator it;
        for (int n = 0; n < len; n ++){
            seq_index[num[n]] = n;
        }
        vector<int> visited(num.size(), 0);
        for (int n = 0; n < len; n ++){
            if (visited[n] == 1) continue;
            visited[n] = 1;
            int seq_len = 1;
            int number = num[n] + 1;
            it = seq_index.find(number);
            while (it != seq_index.end()){
                visited[it->second] = 1;
                seq_len ++;
                number ++;
                it = seq_index.find(number);
            }
            number = num[n] - 1;
            it = seq_index.find(number);
            while (seq_index.find(number) != seq_index.end()){
                visited[it->second] = 1;
                seq_len ++;
                number --;
                it = seq_index.find(number);
            }
            ret = max(ret, seq_len);
        }
        return ret;
    }
};
