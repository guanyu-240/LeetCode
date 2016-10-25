class ListNode(object):
        def __init__(self, value, key, prev, next):
            self.value = value
            self.keys = sets.Set([key])
            self.prev = prev
            self.next = next
            
class AllOne(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.__kvMap = {}
        self.__vList = None
        self.__vListTail = None
        
    def __moveKeyNext(self, vNode, key):
        if vNode is None: return
        if vNode.next:
            vNode.keys.remove(key)
            if vNode.next.value == vNode.value + 1:
                vNode.next.keys.add(key)
            else:
                newNode = ListNode(vNode.value+1, key, vNode, vNode.next)
                vNode.next.prev = newNode
                vNode.next = newNode
            self.__kvMap[key] = vNode.next
            if len(vNode.keys) == 0: #delete the current Node
                vNode.next.prev = vNode.prev
                if vNode.prev: vNode.prev.next = vNode.next
                else: self.__vList = vNode.next
        else:
            if len(vNode.keys) == 1: vNode.value += 1
            else:
                vNode.keys.remove(key)
                vNode.next = ListNode(vNode.value+1, key, vNode, None)
                self.__vListTail = vNode.next
                self.__kvMap[key] = vNode.next
                
    def __moveKeyPrev(self, vNode, key):
        if vNode is None: return
        if vNode.prev: # in this case value can not be 1
            vNode.keys.remove(key)
            if vNode.prev.value == vNode.value - 1:
                vNode.prev.keys.add(key)
            else:
                newNode = ListNode(vNode.value-1, key, vNode.prev, vNode)
                vNode.prev.next = newNode
                vNode.prev = newNode
            self.__kvMap[key] = vNode.prev
            if len(vNode.keys) == 0:
                vNode.prev.next = vNode.next
                if vNode.next: vNode.next.prev = vNode.prev
                else: self.__vListTail = vNode.prev
        else:
            if len(vNode.keys) == 1: 
                vNode.value -= 1
                if vNode.value == 0:
                    if vNode.next: vNode.next.prev = None
                    else: self.__vListTail = None
                    self.__vList = vNode.next
            else:
                vNode.keys.remove(key)
                if vNode.value == 1:
                    del self.__kvMap[key]
                else:
                    vNode.prev = ListNode(vNode.value-1, key, None, vNode)
                    self.__vList = vNode.prev
                    self.__kvMap[key] = vNode.prev
                
    def inc(self, key):
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        :type key: str
        :rtype: void
        """
        vNode = self.__kvMap.get(key)
        if vNode:
            self.__moveKeyNext(vNode, key)
        else:
            if not self.__vList:
                self.__vList = ListNode(1, key, None, None)
                self.__vListTail = self.__vList
            elif self.__vList.value == 1:
                self.__vList.keys.add(key)
            else:
                newNode = ListNode(1, key, None, self.__vList)
                self.__vList.prev = newNode
                self.__vList = newNode
            self.__kvMap[key] = self.__vList

    def dec(self, key):
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        :type key: str
        :rtype: void
        """
        vNode = self.__kvMap.get(key)
        if not vNode: return
        self.__moveKeyPrev(vNode, key)

    def getMaxKey(self):
        """
        Returns one of the keys with maximal value.
        :rtype: str
        """
        if not self.__vListTail: return ""
        return iter(self.__vListTail.keys).next()

    def getMinKey(self):
        """
        Returns one of the keys with Minimal value.
        :rtype: str
        """
        if not self.__vList: return ""
        return iter(self.__vList.keys).next()


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()
