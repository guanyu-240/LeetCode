public class Solution {
    public int getSum(int a, int b) {
        int sum = a^b, carry = (a & b)<<1;
        int tmp = 0;
        while (carry != 0) {
            tmp = sum ^ carry;
            carry = (sum & carry)<< 1;
            sum = tmp;
        }
        return sum;
    }
}
