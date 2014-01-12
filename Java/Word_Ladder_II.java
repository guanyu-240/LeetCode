public class Solution {
    
    private ArrayList<ArrayList<String>> ret = new ArrayList<ArrayList<String>>();
    private HashMap<String, HashSet<String>> predsMap =  new HashMap<String, HashSet<String>>();
    
    public ArrayList<ArrayList<String>> findLadders(String start, String end, HashSet<String> dict) {
        // Initialization
        ret.clear();
        predsMap.clear();
        for (String x : dict) {
            predsMap.put(x, new HashSet<String>());
        }
        predsMap.put(end, new HashSet<String>());
        bfsSearch(start, end, dict);
        ArrayList<String> cand = new ArrayList<String>();
        cand.add(end);
        genResults(cand, start, end);
        return ret;
    }
    
    private void bfsSearch(String start, String end, HashSet<String> dict) {
        HashSet<String> cands = new HashSet<String>();
        Queue<String> q = new LinkedList<String>();
        q.add(start);
        boolean endAtCurLevel = false;
        char original = 0;
        String tmp = null;
        while (!q.isEmpty()) {
            String word = q.remove();
            char wordArray[] = word.toCharArray();
            for (int i = 0; i < wordArray.length; i ++) {
                original = wordArray[i];
                for (char c = 'a'; c <= 'z'; c ++) {
                    wordArray[i] = c;
                    tmp = String.valueOf(wordArray);
                    if (end.equals(tmp)) {
                        endAtCurLevel = true;
                        predsMap.get(end).add(word);
                    }
                    if (dict.contains(tmp)) {
                        predsMap.get(tmp).add(word);
                        cands.add(tmp);
                    }
                }
                wordArray[i] = original;
            }
            if (q.isEmpty()) {
                if (endAtCurLevel) break;
                for (String x : cands) {
                    q.add(x); dict.remove(x);
                }
                cands.clear();
            }
        }
    }
    
    private void genResults(ArrayList<String> cand, String start, String end){
        if (end.equals(start)) {
            ret.add(cand);
            return;
        }
        HashSet<String> preds = predsMap.get(end);
        for (String x : preds) {
            ArrayList<String> newCand = new ArrayList<String>(cand);
            newCand.add(0, x);
            genResults(newCand, start, x);
        }
    }
}
