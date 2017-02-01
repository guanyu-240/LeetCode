public class Solution {
    public int findComplement(int num) {
        long mask = 1;
        while (mask <= num) {
            mask <<= 1;
        }
        mask -= 1;
        return (~num)&(int)mask;
    }
}
