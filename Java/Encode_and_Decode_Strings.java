public class Codec {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for (String s : strs) {
            for (int i = 0; i < s.length(); ++i) {
                sb.append((char)(s.charAt(i)/16+'a'));
                sb.append((char)(s.charAt(i)%16+'a'));
            }
            sb.append(',');
        }
        return sb.toString();
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        List<String> ret = new LinkedList<String>();
        StringBuilder sb = new StringBuilder();
        char c = 0;
        boolean end = false;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == ',') {
                ret.add(sb.toString());
                sb = new StringBuilder();
            }
            else {
                if (end) {
                    c += s.charAt(i)-'a';
                    sb.append(c);
                    c = 0;
                    end = false;
                }
                else {
                    c += 16*(s.charAt(i)-'a');
                    end = true;
                }
            }
        }
        return ret;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));
