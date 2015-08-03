class Solution {
public:
    /*
    Strategy: Divide and Conquer
    */
    vector<int> diffWaysToCompute(string input) {
        vector<int> numbers;
        vector<char> ops;
        vector<int> ret;
        int number = 0;
        for (char &c : input) {
            if (c >= '0' && c <= '9') {
                number = number*10 + (c-'0');
            }
            else {
                numbers.push_back(number);
                ops.push_back(c);
                number = 0;
            }
        }
        numbers.push_back(number);
        ret = solve(numbers, ops, 0, numbers.size()-1);
        return ret;
    }
    
    vector<int> solve(vector<int> &numbers, vector<char> &ops, int start, int end) {
        vector<int> ret;
        if (start == end) {
            ret.push_back(numbers[start]);
        }
        else {
            for (int i = start; i < end; i ++) {
                vector<int> left = solve(numbers, ops, start, i);
                vector<int> right = solve(numbers, ops, i+1, end);
                for (int x : left) {
                    for (int y : right) {
                        ret.push_back(compute(x,y,ops[i]));
                    }
                }
            }
        }
        return ret;
        
    }
    int compute(int x, int y, char op) {
        switch(op) {
            case '+': return x+y;
            case '-': return x-y;
            case '*': return x*y;
            default: return 0;
        }
        return 0;
    }
};
