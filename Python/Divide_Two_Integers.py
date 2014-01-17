class Solution:
    # @return an integer
    """
    Idea: dividend = divisor*(a(n)2^n + a(n - 1)2^(n - 1) + ... + a(1)2^1 + a(0)2^0)
    a(i) = 1 or 0 (0 <= i <= n)
    From high to low, calculate a(n)
    Each time, shift divisor by i when shifting 1 more bit will cause (dividend - divisor) < 0
    In this process we can get an divisor*2^i. 2^i will be the part of the return value. 
    Then decrement the dividend by divisor*2^i.
    Do this process again and again until dividend equals 0.
    In this way, any bit i in which a(i) = 0 will be skipped.
    """
    def divide(self, dividend, divisor):
        if dividend == 0: return 0
        dend = abs(long(dividend))
        div = abs(long(divisor))
        tmpDiv = div
        ret = long(0)
        assert div > 0
        while dend > 0:
            tmpDiv = div
            count = 0
            while dend >= tmpDiv:
                tmpDiv = tmpDiv << 1
                count =  count + 1
            dend = dend - (tmpDiv >> 1)
            ret = ret + (0 if count == 0 else long(pow(2, count-1)))
        if (divisor > 0 and dividend > 0) or (divisor < 0 and dividend < 0): return int(ret)
        else: return int(-ret)
