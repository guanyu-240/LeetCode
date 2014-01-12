class Solution:
    # @return a string
    def longestPalindrome(self, s):
        n = len(s)
        if (n == 0): return s
        maxLen = 0
        maxStart = 0
        ptr1 = 0
        ptr2 = 0
        for i in range(n):
            ptr1 = i - 1
            ptr2 = i + 1
            while ptr1 >= 0 and ptr2 < n and s[ptr1] == s[ptr2]:
                ptr1 = ptr1 - 1
                ptr2 = ptr2 + 1
            if ptr2-ptr1-1 >= maxLen:
                maxLen = ptr2-ptr1-1
                maxStart = ptr1 + 1
            ptr1 = i
            ptr2 = i+1
            while ptr1 >= 0 and ptr2 < n and s[ptr1] == s[ptr2]:
                ptr1 = ptr1 - 1
                ptr2 = ptr2 + 1
            if ptr2-ptr1-1 >= maxLen:
                maxLen = ptr2-ptr1-1
                maxStart = ptr1 + 1
        return s[maxStart: maxStart+maxLen]
