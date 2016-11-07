public class Solution {
    private char toHexChar(int x) {
        if (x > 15 || x < 0) return '\0';
        else if (x < 10) return (char)('0'+x);
        else return (char)('a'+x-10);
    }
    public String toHex(int num) {
        StringBuilder sb = new StringBuilder();
        while (num != 0) {
            sb.append(toHexChar(num&15));
            num >>>= 4;
        }
        if (sb.length() == 0) sb.append('0');
        return sb.reverse().toString();
    }
    
}
