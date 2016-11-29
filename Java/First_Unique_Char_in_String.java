public class Solution {
    public int firstUniqChar(String s) {
        int n = s.length();
        int ret = -1;
        int[][] char_count = new int[2][26];
        while (n-- > 0) {
            char_count[0][s.charAt(n)-'a']++;
            char_count[1][s.charAt(n)-'a'] = n;
        }
        while (++n < 26) {
            if (char_count[0][n] == 1) {
                if (ret == -1 || ret > char_count[1][n]) {
                    ret = char_count[1][n];
                }
            }
        }
        return ret;
    }
}
