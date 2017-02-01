public class Solution {
    public int findSubstringInWraproundString(String p) {
        int n = p.length();
        if (n == 0) return 0;
        int ret = 0;
        int[] max_end = new int[26];
        int cur_seq = 1;
        max_end[p.charAt(0)-'a'] = 1;
        for (int i = 1; i < n; ++i) {
            if ((p.charAt(i)-p.charAt(i-1)+25) % 26 == 0) {
                cur_seq ++;
            }
            else {
                cur_seq = 1;
            }
            max_end[p.charAt(i)-'a'] = Math.max(max_end[p.charAt(i)-'a'], cur_seq);
        }
        for (int i = 0; i < 26; ++i) {
            ret += max_end[i];
        }
        return ret;
    }
}
