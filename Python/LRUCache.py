class LRUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
        self.__cacheMap = {}
        self.__cacheList = None
        self.__cacheListEnd = None
        self.__capacity = max(capacity, 1)

    # @return an integer
    def get(self, key):
        if key not in self.__cacheMap: return -1
        node = self.__cacheMap[key]
        self.__moveToEnd(node)
        return node.v

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def put(self, key, value):
        if key not in self.__cacheMap:
            self.__addNew(key, value)
        else:
            node = self.__cacheMap[key]
            node.v = value
            self.__moveToEnd(node)
    
    # add a new page
    def __addNew(self, k, v):
        newNode = CacheNode(k, v, None, None)
        if self.__cacheList == None:
            self.__cacheList = newNode;
        else:
            self.__cacheListEnd.ne = newNode
            newNode.pre = self.__cacheListEnd
        self.__cacheListEnd = newNode
        self.__cacheMap[k] = newNode
        if len(self.__cacheMap) > self.__capacity:
            del self.__cacheMap[self.__cacheList.k]
            self.__cacheList.ne.pre = None
            self.__cacheList = self.__cacheList.ne

    # move a page to the end of the list
    def __moveToEnd(self, node):
        if node == self.__cacheListEnd: return
        node.ne.pre = node.pre
        if node == self.__cacheList:
            self.__cacheList = node.ne
        else:
            node.pre.ne = node.ne
        self.__cacheListEnd.ne = node
        node.pre = self.__cacheListEnd
        node.ne = None
        self.__cacheListEnd = node
        
class CacheNode:
    def __init__(self, k, v, pre, ne):
        self.k = k
        self.v = v
        self.pre = pre
        self.ne = ne

