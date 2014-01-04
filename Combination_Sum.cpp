class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<vector<int>>> table(target + 1);
        table.clear();
        int len = candidates.size();
        for (int n = 0; n < len; n ++){
            int cand_num = candidates[n];
            vector<int> cand;
            cand.push_back(cand_num);
            if (cand_num <= target){
                table[cand_num].push_back(cand);
            }
        }
        
        for (int i = 0; i <= target; i ++){
            int size = table[i].size();
            if (size == 0){
                continue;
            }
            for (int j = 0; j < size; j ++){
                vector<int> cand(table[i][j]);
                for (int k = 0; k < len; k ++){
                    int tmp = candidates[k];
                    if(tmp < cand[cand.size() - 1]){
                        continue;
                    }
                    vector<int> cand_new (cand);
                    cand_new.push_back(tmp);
                    int sum = i + tmp;
                    if (sum <= target){
                        table[sum].push_back(cand_new);
                    }
                }
            }
        }
        return table[target];
    }
};
