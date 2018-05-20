class Solution(object):
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        n = len(S)
        large_groups = []
        length = 1
        for pos in range(1, n):
            if S[pos] == S[pos-1]:
                length += 1
            else:
                if length >= 3:
                    large_groups.append([pos-length, pos-1])
                length = 1
            if pos == n-1 and length >= 3:
                large_groups.append([pos-length+1, pos])
        return large_groups
