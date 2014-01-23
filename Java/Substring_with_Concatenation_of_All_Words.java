public class Solution {
    private HashMap<String, Integer> expected = new HashMap<String, Integer>();
    private HashMap<String, Integer> actual = new HashMap<String, Integer>();
    private ArrayList<Integer> ret = new ArrayList<Integer>();
    public ArrayList<Integer> findSubstring(String S, String[] L) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        expected.clear();
        ret.clear();
        if (L.length == 0) return ret;
        int n = S.length(), k = L[0].length();
        if (k == 0) return ret;
        int m = k*L.length;
        if (m > n) return ret;

        for (String s : L) {
            Integer count = expected.get(s);
            if (count == null) expected.put(s, 1);
            else expected.put(s, count + 1);
        }
        
        Integer expectedCount = null, actualCount = null;
        boolean valid = true;
        for (int i = 0; i <= n-m; i ++) {
            actual.clear();
            valid = true;
            for (int j = i; j < i+m; j += k) {
                String sub = S.substring(j, j+k);
                expectedCount = expected.get(sub);
                if (expectedCount == null) {
                    valid = false;
                    break;
                }
                actualCount = actual.get(sub);
                if (actualCount == null) {
                    actual.put(sub, 1);
                }
                else if (actualCount < expectedCount) {
                    actual.put(sub, actualCount+1);
                }
                else {
                    valid = false;
                    break;
                }
            }
            if (valid) ret.add(i);
        }
        
        return ret;
    }
}
