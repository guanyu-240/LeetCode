public class Solution {
    public String licenseKeyFormatting(String S, int K) {
        StringBuilder k_builder = new StringBuilder();
        for (int i = S.length()-1; i >= 0; i --) {
            if (S.charAt(i) != '-') {
                if ((k_builder.length()+1)%(K+1) == 0) {
                    k_builder.append('-');
                }
                k_builder.append(Character.toUpperCase(S.charAt(i)));
            }
        }
        return k_builder.reverse().toString();
    }
}
