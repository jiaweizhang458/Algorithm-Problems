#Given a non-overlapping interval list which is sorted by start point.
#Insert a new interval into it, make sure the list is still in order and non-overlapping (merge intervals if necessary).

#Insert (2, 5) into [(1,2), (5,9)], we get [(1,9)].
#Insert (3, 4) into [(1,2), (5,9)], we get [(1,2), (3,4), (5,9)].


#Solution 1: while
#Reference: https://www.cnblogs.com/grandyang/p/4367569.html
"""
Definition of Interval.
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    """
    @param intervals: Sorted interval list.
    @param newInterval: new interval.
    @return: A new interval list.
    """
    def insert(self, intervals, newInterval):
        result = []
        num = len(intervals)
        if (num == 0):
            result.append(newInterval)
            return result
        
        i = 0
        while (i < num and intervals[i].end < newInterval.start):
            result.append(intervals[i])
            i += 1
        while (i < num and intervals[i].start <= newInterval.end):
            newInterval.start = min(newInterval.start, intervals[i].start)
            newInterval.end = max(newInterval.end, intervals[i].end)
            i += 1
        result.append(newInterval)
        while (i < num):
            result.append(intervals[i])
            i += 1
        return result
