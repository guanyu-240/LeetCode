public class Solution {
    private List<String> ret;
    public List<String> generateAbbreviations(String word) {
        ret = new LinkedList<String>();
        StringBuilder pred = new StringBuilder();
        solve(word, 0, pred);
        return ret;
    }
    private void solve(String word, int idx, StringBuilder pred) {
        /*
         * DFS solution
         */
        if (idx >= word.length()) {
            ret.add(pred.toString());
            return;
        }
        pred.append(word.charAt(idx));
        solve(word, idx+1, pred);
        pred.setLength(pred.length()-1);
        inc_dec_one(pred, true);
        solve(word, idx+1, pred);
        inc_dec_one(pred, false);
    }
    private void inc_dec_one(StringBuilder pred, boolean inc) {
        int new_length = pred.length();
        char c;
        int count = 0, base = 1;
        while (new_length > 0) {
            c = pred.charAt(new_length-1);
            if (c >= '0' && c <= '9') {
                count += base*(c - '0');
                base *= 10;
                new_length--;
            }
            else {
                break;
            }
        }
        count += inc ? 1 : -1;
        pred.setLength(new_length);
        if (count > 0) pred.append(count);
    }
}
