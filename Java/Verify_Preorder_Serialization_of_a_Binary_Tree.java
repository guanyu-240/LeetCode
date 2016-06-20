public class Solution {
    public boolean isValidSerialization(String preorder) {
        int i = 0;
        int nodesAllowed = 1;
        while (i < preorder.length()) {
            if (preorder.charAt(i) == ',') i ++;
            else if (preorder.charAt(i) == '#') {  // When a null node is detected
                i ++;
                nodesAllowed --;
                if (nodesAllowed < 0) return false;
            }
            else {
                while (i < preorder.length() && preorder.charAt(i) != ',') i ++;
                if (nodesAllowed == 0) return false;
                nodesAllowed ++;
            }
        }
        return nodesAllowed == 0 ? true : false;
    }
}
