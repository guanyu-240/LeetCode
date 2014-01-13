class LRUCache:
    def __init__(self, capacity):
        self.__cacheMap = {}
        self.__cacheList = None
        self.__cacheListEnd = None
        self.__capacity = max(capacity, 1)

    def get(self, key):
        node = self.__cacheMap.get(key)
        if node == None: return -1
        self.__moveToEnd(node)
        return node.v

    def set(self, key, value):
        node = self.__cacheMap.get(key)
        if node == None:
            self.__addNew(key, value)
        else:
            node.v = value
            self.__moveToEnd(node)

    def __addNew(self, k, v):
        # first check whether remove LRU is needed
        if len(self.__cacheMap) == self.__capacity:
            del self.__cacheMap[self.__cacheList.k]
            # modify the cache list
            if self.__capacity == 1:
                self.__cacheList = None
                self.__cacheListEnd = None
            else:
                self.__cacheList.ne.pre = None
                self.__cacheList = self.__cahceList.ne
        newNode = CacheNode(k, v, None, None)
        if self.__cacheList == None:
            self.__cacheList = newNode;
        else:
            self.__cacheListEnd.ne = newNode
            newNode.pre = self.__cacheListEnd
        self.__cacheListEnd = newNode
        self.__cacheMap[k] = newNode

    def __moveToEnd(self, node):
        if node == self.__cacheListEnd: return
        if node == self.__cacheList:
            self.__cacheList.ne.pre = None
            self.__cacheList = self.__cacheList.ne
        self.__cacheListEnd.ne = node
        node.pre = self.__cacheListEnd
        self.__cacheListEnd = node

class CacheNode:
    def __init__(self, k, v, pre, ne):
        self.k = k
        self.v = v
        self.pre = pre
        self.ne = ne


