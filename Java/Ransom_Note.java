public class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int n1 = ransomNote.length(), n2 = magazine.length();
        if (n1 == 0) return true;
        int[] char_count = new int[26];
        int ptr = 0;
        while (ptr < n2) {
            char_count[magazine.charAt(ptr++)-'a']++;
        }
        ptr = 0;
        while (ptr < n1) {
            if (char_count[ransomNote.charAt(ptr++)-'a']-- == 0) return false;
        }
        return true;
    }
}
