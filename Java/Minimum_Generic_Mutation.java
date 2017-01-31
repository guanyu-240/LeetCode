public class Solution {
    public int minMutation(String start, String end, String[] bank) {
        if(start==null || end==null || start.length()!=end.length()) return -1;
        HashMap<String, Boolean> genes = new HashMap<>();
        for (String g : bank) {
            genes.put(g, false);
        }
        if (!genes.containsKey(end)) return -1;
        
        Queue<String> q = new LinkedList<String>();
        int n = start.length();
        int ret = 1;
        int cntCurLvl = 1;
        StringBuilder cur = null;
        String curStr = null;
        char[] pool = new char[]{'A','T','C','G'};
        q.add(start);
        while (!q.isEmpty()) {
            cur = new StringBuilder(q.poll());
            cntCurLvl --;
            for (int i = 0; i < n; ++ i) {
                char original = cur.charAt(i);
                for (int j = 0; j < 4; ++ j) {
                    if (pool[j] != original) {
                        cur.setCharAt(i, pool[j]);
                        curStr = cur.toString();
                        if (curStr.equals(end)) {
                            return ret;
                        }
                        if (genes.containsKey(curStr) && !genes.get(curStr)) {
                            q.add(curStr);
                            genes.put(curStr, true);
                        }
                    }
                }
                cur.setCharAt(i, original);
            }
            
            if (cntCurLvl == 0) {
                cntCurLvl = q.size();
                ret ++;
            }
        }
        return -1;
    }
}
