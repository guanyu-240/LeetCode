# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    # @param intervals, a list of Intervals
    # @param newInterval, a Interval
    # @return a list of Interval
    def insert(self, intervals, newInterval):
        ret = []
        inserted = False
        for itv in intervals:
            if itv.end < newInterval.start:
                ret.append(itv)
            elif itv.start > newInterval.end:
                if not inserted:
                    ret.append(newInterval)
                    inserted = True
                ret.append(itv)
            else:
                newInterval.start = min(itv.start, newInterval.start)
                newInterval.end = max(itv.end, newInterval.end)
        if not inserted: ret.append(newInterval)
        return ret
