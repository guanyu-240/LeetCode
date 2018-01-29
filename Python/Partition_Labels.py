class Solution(object):
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        index = {}
        n = len(S)
        for i in range(n):
            index[S[i]] = i
        # Partition into sequences
        res = []
        seq_end_prev = -1
        seq_end = 0
        for i in range(n):
            if index[S[i]] == i:
                if seq_end <= i:
                    seq_end = i
                    res.append(seq_end - seq_end_prev)
                    seq_end_prev = seq_end
            else:
                if index[S[i]] > seq_end: seq_end = index[S[i]]
        return res
