class Solution:
    # @return a boolean
    def isPalindrome(self, x):
        if x < 0: return False
        divisor = 1
        while x / divisor > 0:
            divisor = divisor * 10
        divisor = divisor / 10
        left = 0
        right = 0
        while x > 0:
            left = x / divisor
            right = x % 10
            if not left == right: return False
            x = (x % divisor)/10     # stripe the left and right digit
            divisor = divisor / 100  # 2 digits striped, so stripe 2 digits from divisor as well
        return True
