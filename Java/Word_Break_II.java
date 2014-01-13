public class Solution {
    ArrayList<String> ret = new ArrayList<String>();
    public ArrayList<String> wordBreak(String s, Set<String> dict) {
        ret.clear();
        int n = s.length();
        if (n == 0) {
            ret.add("");
            return ret;
        }
        boolean[][] exist = new boolean[n][n];
        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j ++) {
                if (dict.contains(s.substring(i, j+1))) {
                    exist[i][j] = true;
                }
                else {
                    exist[i][j] = false;
                }
            }
        }
        trace(s, exist, new StringBuilder(""), n-1);
        return ret;
    }
    
    private void trace(String s, boolean[][] exist, StringBuilder cand, int end) {
        for (int i = 0; i <= end; i ++) {
            if (exist[i][end]) {
                StringBuilder newCand = new StringBuilder(cand);
                newCand.insert(0, s.substring(i, end+1));
                if (i == 0) {
                    ret.add(newCand.toString());
                }
                else {
                    newCand.insert(0, ' ');
                    trace(s, exist, newCand, i-1);
                }
            }
        }
    }
}
