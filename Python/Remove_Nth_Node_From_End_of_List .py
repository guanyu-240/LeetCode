# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @return a ListNode
    def removeNthFromEnd(self, head, n):
        ptr = head
        endPtr = head
        while n > 1:
            n = n - 1
            if endPtr.next is not None:
                endPtr = endPtr.next
            else: return head
        pre = None
        while endPtr.next is not None:
            pre = ptr
            ptr = ptr.next
            endPtr = endPtr.next
        if pre == None:
            head = ptr.next
        else:
            pre.next = ptr.next
        return head
