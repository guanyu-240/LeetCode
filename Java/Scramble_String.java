public class Solution {
    public boolean isScramble(String s1, String s2) {
        if (!equalCharCount(s1, s2)) return false;
        if (s1.length() <= 3) return true;
        for (int i = 1; i < s1.length(); i ++) {
            if (isScramble(s1.substring(0, i), s2.substring(0, i)) && 
                isScramble(s1.substring(i, s1.length()), s2.substring(i, s2.length()))){
                return true;
            }
            if (isScramble(s1.substring(0, i), s2.substring(s2.length()-i, s2.length())) &&
                isScramble(s1.substring(i, s1.length()), s2.substring(0, s2.length()-i))){
                return true;
            }
        }
        return false;
    }
    
    private boolean equalCharCount(String s1, String s2) {
        if (s1.length() != s2.length()) return false;
        int count[] = new int[256];
        Arrays.fill(count, 0);
        int n = s1.length();
        for (int i = 0; i < n; i ++) {
            count[s1.charAt(i)] ++;
            count[s2.charAt(i)] --;
        }
        for (int i = 0; i < 256; i ++) {
            if (count[i] != 0) return false;
        }
        return true;
    }
}
