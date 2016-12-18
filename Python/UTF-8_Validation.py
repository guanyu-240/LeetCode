class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        if len(data) <= 0: return False
        mask = 1 << 7
        if len(data) == 1: return not data[0]&mask == mask
        count = 0
        for d in data:
            if count == 0:
                while d&mask == mask:
                    count += 1
                    d <<= 1
                if count == 1: return False
                count = max(count-1, 0)
            else:
                if d&mask == mask and (d<<1)&mask == 0:
                    count -= 1
                else: return False
        return count == 0
