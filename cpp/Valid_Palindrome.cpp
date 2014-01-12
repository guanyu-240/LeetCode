class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start_ptr = 0;
        int end_ptr = s.length() - 1;
        while (start_ptr < end_ptr){
            char c1 = s[start_ptr];
            char c2 = s[end_ptr];
            if (!isLetterOrNumber(c1)) {
                start_ptr ++;
                continue;
            }
            if (!isLetterOrNumber(c2)) {
                end_ptr --;
                continue;
            }
            if (tolower(c1) == tolower(c2)){
                start_ptr ++;
                end_ptr --;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool isLetterOrNumber(char c){
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
};
