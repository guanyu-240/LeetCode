# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    # @param intervals, a list of Interval
    # @return a list of Interval
    def merge(self, intervals):
        if len(intervals) <= 1: return intervals
        intervals.sort(key = lambda x: x.start)
        ret = []
        ret.append(intervals[0])
        n = len(intervals)
        for i in range(1, n):
            if ret[-1].end >= intervals[i].start:
                ret[-1].end = max(ret[-1].end, intervals[i].end)
            else:
                ret.append(intervals[i])
        return ret
