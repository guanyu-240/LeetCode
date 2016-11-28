public class Solution {
    public String decodeString(String s) {
        StringBuilder ret = new StringBuilder();
        Stack<Integer> repeats = new Stack<Integer>();
        Stack<StringBuilder> repeatedStr = new Stack<StringBuilder>();
        String tmpStr;
        char c;
        int num = 0, repeat = 0;
        for (int i = 0; i < s.length(); i ++) {
            repeat = repeats.empty() ? 0 : repeats.peek();
            c = s.charAt(i);
            if (c >= '0' && c <= '9') {
                num = num*10+(c-'0');
            } 
            else if (c == '[') {
                repeats.push(num);
                repeatedStr.push(new StringBuilder());
                num = 0;
            }
            else if (c == ']') {
                repeats.pop();
                tmpStr = repeatedStr.pop().toString();
                if (repeatedStr.empty()) {
                    while (repeat-- > 0) ret.append(tmpStr);
                }
                else {
                    while (repeat-- > 0) repeatedStr.peek().append(tmpStr);
                }
            }
            else {
                if (repeat == 0) ret.append(c);
                else repeatedStr.peek().append(c);
            }
        }
        return ret.toString();
    }
}
