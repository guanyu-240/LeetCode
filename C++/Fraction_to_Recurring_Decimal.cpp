class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return "";
        bool negative = (numerator > 0 && denominator < 0) || 
                        (numerator < 0 && denominator > 0) ? true : false;
        long long dividend = llabs((long long)numerator), divisor = llabs((long long)denominator);
        long long beforePoint = dividend / divisor, remain = dividend % divisor;
        long long digit = 0; 
        int index = 1;
        unordered_map<long long, int> dividend_index;
        unordered_map<long long, int>::iterator it; 
        queue<long long> numbers;
        numbers.push(beforePoint);
        while (remain > 0) {
            dividend = remain * 10;
            digit = dividend / divisor;
            remain = dividend % divisor;
            if ((it = dividend_index.find(dividend)) != dividend_index.end()) {
                return extractQueue(numbers, negative, it->second);
            }
            numbers.push(digit);
            dividend_index[dividend] = index;
            index ++;
        }
        return extractQueue(numbers, negative, -1);
    }
    string extractQueue(queue<long long> &numbers, bool negative, int repeatStart) {
        if (numbers.empty()) return "";
        string ret = "";
        if (negative) ret += "-";
        ret += to_string(numbers.front());
        numbers.pop();
        if (numbers.empty()) return ret;
        ret += ".";
        int index = 1;
        while (!numbers.empty()) {
            if (index == repeatStart) {
                ret += "(";
            }
            ret += to_string(numbers.front());
            numbers.pop();
            index ++;
        }
        if (repeatStart >= 1) ret += ")";
        return ret;
    }
};
