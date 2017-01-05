class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        n = len(num)
        if k >= n: return '0'
        count = 1
        idx = 0
        st = []
        # Always select the peak starting from the beginning
        while count <= k:
            if len(st) > 0 and (idx == len(num) or st[len(st)-1] > num[idx]):
                st.pop()
                count += 1
            else: 
                st.append(num[idx])
                idx += 1
        tmp = ''.join(st) + num[idx:]
        start = 0
        while start < len(tmp):
            if tmp[start] == '0': start += 1
            else: break
        if start == len(tmp): return '0'
        else: return tmp[start:]
