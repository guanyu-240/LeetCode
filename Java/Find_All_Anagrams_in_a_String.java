public class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> ret = new LinkedList<Integer>();
        if (s.length() < p.length()) return ret;
        
        int[] diff = new int[26];
        int offset = 0;
        Arrays.fill(diff, 0);
        for (int i = 0; i < p.length(); ++i) {
            diff[p.charAt(i)-'a'] ++;
            diff[s.charAt(i)-'a'] --;
        }
        
        for (int j = 0; j < 26; ++j) {
            offset += Math.max(0, diff[j]);
        }
        if (offset == 0) ret.add(0);
        for (int k = p.length(); k < s.length(); ++k) {
            char c1 = s.charAt(k), c2 = s.charAt(k-p.length());
            if (c1 != c2) {
                diff[c2-'a'] ++;
                diff[c1-'a'] --;
                if (diff[c2-'a'] <= 0 && diff[c1-'a'] >= 0) {
                    offset --;
                }
                else if (diff[c2-'a'] > 0 && diff[c1-'a'] < 0) {
                    offset ++;
                }
            }
            if (offset == 0) ret.add(k-p.length()+1);
        }
        return ret;
    }
}
