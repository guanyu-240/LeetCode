# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        diff = 0
        ptr1,ptr2 = l1,l2
        while ptr1 != None or ptr2 != None:
            if ptr1 is None: diff -= 1
            elif ptr2 is None: diff += 1
            ptr1 = None if ptr1 == None else ptr1.next
            ptr2 = None if ptr2 == None else ptr2.next
        return self.addTwoLists(l1, l2, diff, True)
        
    def addTwoLists(self, l1, l2, diff, final):
        if l1 is None and l2 is None: return None
        ret = ListNode(0)
        if diff > 0:
            ret.val = l1.val
            ret.next = self.addTwoLists(l1.next, l2, diff-1, False)
        elif diff < 0:
            ret.val = l2.val
            ret.next = self.addTwoLists(l1, l2.next, diff+1, False)
        else:
            ret.val = l1.val + l2.val
            ret.next = self.addTwoLists(l1.next, l2.next, 0, False)
        if ret.next is not None and ret.next.val >= 10: 
            ret.next.val %= 10
            ret.val += 1
        if final and ret.val >= 10:
            ret.val %= 10
            tmp = ret
            ret = ListNode(1)
            ret.next = tmp
        return ret
