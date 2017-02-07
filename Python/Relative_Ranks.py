class Solution(object):
    def output_rank(self, rank):
        if rank == 1: return "Gold Medal"
        elif rank == 2: return "Silver Medal"
        elif rank == 3: return "Bronze Medal"
        else: return str(rank)
        
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        n = len(nums)
        scores = []
        ranks = [None for i in range(n)]
        for i in range(n):
            scores.append([nums[i], i])
        scores.sort()
        for r in range(n):
            ranks[scores[r][1]] = self.output_rank(n-r)
        return ranks
