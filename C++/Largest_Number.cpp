class Solution {
public:
    static bool compare(int n1, int n2){
        string s1 = to_string(n1) + to_string(n2);
        string s2 = to_string(n2) + to_string(n1);
        int len = s1.length();
        for (int i = 0; i < len; i ++) {
            if (s1[i] != s2[i]) return s1[i] > s2[i];
        }
        return false;
    }
    string largestNumber(vector<int> &num) {
        if (num.size() == 0) return "";
        sort(num.begin(), num.end(), compare);
        vector<int>::iterator it;
        string number = "";
        for (it = num.begin(); it != num.end(); ++ it) {
            number = number + to_string(*it);
        }
        if (number.length() == 0) return number;
        int i = 0;
        while (i < number.length()) {
            if (number[i] != '0') return number.substr(i, number.length()-i);
            i ++;
        }
        return "0";
    }
};
