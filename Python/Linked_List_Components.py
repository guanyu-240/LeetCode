# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def numComponents(self, head, G):
        """
        :type head: ListNode
        :type G: List[int]
        :rtype: int
        """
        num_components = 0
        Gset = set(G)
        ptr = head
        is_component = False
        while ptr is not None:
            if ptr.val in Gset:
                is_component = True
                if ptr.next is None:
                    num_components += 1
            elif is_component:
                num_components += 1
                is_component = False
            ptr = ptr.next
        return num_components
