public class Solution {
    private char toHexChar(long x) {
        if (x > 15 || x < 0) return '\0';
        else if (x < 10) return (char)('0'+(int)x);
        else return (char)('a'+(int)(x-10));
    }
    public String toHex(int num) {
        long x = ~((long)1 << 63) & num;
        StringBuilder sb = new StringBuilder();
        while (x != 0) {
            sb.append(toHexChar(x%16));
            x /= 16;
            if (sb.length() == 8) break;
        }
        if (sb.length() == 0) sb.append('0');
        return sb.reverse().toString();
    }
    
}
