class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        stack <string> st;
        if (path[path.length()-1] != '/') path.append(1, '/');
        i = 0;
        int countDot = 0;
        string dirOrFile("");
        int len = path.length();
        while (i < len) {
            if (path[i] == '/') {
                if (countDot > 0 && dirOrFile.length() == countDot) {  
                    if (countDot == 2 && !st.empty()) st.pop(); 
                    if (countDot > 2) st.push(dirOrFile);
                }
                else {
                    if (dirOrFile.length() > 0) {  
                        st.push(dirOrFile);
                    }
                }
                dirOrFile = string("");
                countDot = 0;
            }
            else {
                dirOrFile.append(1, path[i]);
                if (path[i] == '.') countDot ++;
            }
            ++i;
        }
        string ret("");
        while (!st.empty()) {
            ret.insert(0, st.top());
            ret.insert(0, 1, '/');
            st.pop();
        }
        if (ret == "") ret.append(1, '/');
        return ret;
    }
};
