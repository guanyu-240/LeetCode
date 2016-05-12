public class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        if (k == 0) return 0; 
        
        int tmpLongest = 0;
        Integer count = null;
        int ret = 0;
        HashMap<Character, Integer> charCount = new HashMap<Character, Integer>();
        
        for (int i = 0; i < s.length(); i ++) {
            char c =  s.charAt(i);
            count = charCount.get(c);
            tmpLongest ++;
            
            if (count == null) { charCount.put(c, 1); }
            else { charCount.put(c, count+1); }
            
            if (charCount.size() > k) {
                int j = i+1-tmpLongest;
                while (j < i) {
                    tmpLongest --;
                    c = s.charAt(j);
                    count = charCount.get(c);
                    count--;
                    if (count == 0) { 
                        charCount.remove(c);
                        break;
                    }
                    charCount.put(c, count);
                    j++;
                }
            }
            ret = Math.max(ret, tmpLongest);
        }
        
        return ret;
    }
}
