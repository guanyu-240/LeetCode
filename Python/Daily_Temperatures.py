class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        n = len(temperatures)
        if n == 0: return []
        st = [(temperatures[0], 0)]
        res = [0 for i in range(n)]
        for i in range(1, n):
            while len(st) > 0 and temperatures[i] > st[len(st)-1][0]:
                t = st.pop()
                res[t[1]] = i - t[1]
            st.append((temperatures[i], i))
        while len(st) > 0:
            t = st.pop()
            res[t[1]] = 0
        return res
