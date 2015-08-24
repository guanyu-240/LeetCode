public class Solution {
    public List<String> generatePalindromes(String s) {
        HashMap<Character, Integer> c_count = new HashMap();
        Integer count;
        int count_odd = 0;
        for (int i = 0; i < s.length(); i ++) {
            count = c_count.get(s.charAt(i));
            if (count != null) {
                count ++;
                c_count.put(s.charAt(i), count);
            }
            else c_count.put(s.charAt(i), 1);
        }
        
        char odd_char = '\0';
        for (Map.Entry<Character, Integer> e : c_count.entrySet()) {
            if (e.getValue() % 2 != 0) {
                count_odd ++;
                odd_char = e.getKey();
            }
            if (count_odd > 1) return (new LinkedList<String>());
            e.setValue(e.getValue() / 2);
        }
        
        List<String> ret = solve(c_count);
        for (ListIterator<String> it_l = ret.listIterator(); it_l.hasNext(); ) {
            String cand = it_l.next();
            String cand_rv = (new StringBuilder(cand)).reverse().toString();
            if (count_odd > 0) cand += odd_char;
            cand += cand_rv;
            it_l.set(cand);
        }
        return ret;
    }
    private List<String> solve(HashMap<Character, Integer> c_count) {
        List<String> ret = new LinkedList<String>();
        for (Map.Entry<Character, Integer> e : c_count.entrySet()) {
            if (e.getValue() != 0) {
                e.setValue(e.getValue()-1);
                for (String s : solve(c_count)) {
                    ret.add(s+e.getKey());
                }
                e.setValue(e.getValue()+1);
            }
        }
        if (ret.size() == 0) ret.add("");
        return ret;
    }
}
