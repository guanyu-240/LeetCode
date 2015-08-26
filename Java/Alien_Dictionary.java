public class Solution {
    public String alienOrder(String[] words) {
        int n = words.length;
        if (n == 0) return "";
        if (n == 1) return words[0];
        
        /* start constructing graph */
        int a = (int)'a';
        List<Character>[] adjList = new List[26];
        for (int i = 0; i < 26; ++i) { adjList[i] = new LinkedList<Character>(); }
        int[] countIncoming = new int[26];
        Arrays.fill(countIncoming, -1);
        for (String w : words) {
            for (int i = 0; i < w.length(); ++i) {
                countIncoming[(int)w.charAt(i)-a] = 0;
            }
        }
        
        int ptr = 0, lb = 0;
        for (int i = 1; i < n; i ++) {
            ptr = 0;
            lb = Math.min(words[i].length(), words[i-1].length());
            while (ptr < lb && words[i].charAt(ptr) == words[i-1].charAt(ptr)) {
                ptr ++;
            }
            if (ptr < lb) {
                adjList[(int)words[i-1].charAt(ptr)-a].add(words[i].charAt(ptr));
                countIncoming[(int)words[i].charAt(ptr)-a] ++;
            }
        }
        
        /* start topological sort process */
        StringBuilder ret = new StringBuilder();
        Queue<Character> q = new LinkedList<Character>();
        char tmp;
        for (char c = 'a'; c <= 'z'; c ++) {
            if (countIncoming[(int)c-a] == 0) q.add(c);
        }
        while (!q.isEmpty()) {
            tmp = q.poll();
            ret.append(tmp);
            for (char c : adjList[(int)tmp-a]) {
                countIncoming[(int)c-a] --;
                if (countIncoming[(int)c-a] == 0) {
                    q.add(c);
                }
            }
        }
        
        for (int i = 0; i < 26; ++i) {
            if (countIncoming[i] > 0) return "";
        }
        return ret.toString();
    }
}
