# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        ptr1 = l1
        ptr2 = l2
        carry = 0
        ret = None
        ptr = ret
        while not (ptr1 == None and ptr2 == None):
            digit = 0
            if not ptr1 == None:
                digit = digit + ptr1.val
                ptr1 = ptr1.next
            if not ptr2 == None:
                digit = digit + ptr2.val
                ptr2 = ptr2.next
            digit = digit + carry;
            carry = digit / 10
            digit = digit % 10
            newNode = ListNode(digit)
            if (ret == None): ret = newNode
            else: ptr.next = newNode
            ptr = newNode
        if carry > 0:
            newNode = ListNode(carry)
            ptr.next = newNode
        return ret
