class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return constructSolutions(n, true);
    }
    vector<string> constructSolutions(int n, bool noZero) {
        if (n == 0) return vector<string>(1, "");
        else if (n == 1){
            return vector<string> { "0", "1", "8" };
        }
        else {
            vector<string> ret;
            vector<string> tmp = constructSolutions(n-2, false);
            for (string s : tmp) {
                ret.push_back("1"+s+"1");
                ret.push_back("8"+s+"8");
                ret.push_back("6"+s+"9");
                ret.push_back("9"+s+"6");
                if (!noZero) ret.push_back("0"+s+"0");
            }
            return ret;
        }
    }
};
