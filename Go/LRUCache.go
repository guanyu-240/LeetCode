// node in cache list
type CacheNode struct {
    key   int
    value int
    prev  *CacheNode
    next  *CacheNode
}
type LRUCache struct {
    cacheMap       map[int]*CacheNode
    cacheList      *CacheNode
    cacheListEnd   *CacheNode
    capacity       int
}


func Constructor(capacity int) LRUCache {
    return LRUCache {
        cacheMap     : make(map[int]*CacheNode),
        cacheList    : nil,
        cacheListEnd : nil,
        capacity     : capacity,
    }
}

// move a node to the end of the cache list
func (this *LRUCache) moveToEnd (node *CacheNode) {
    if node == this.cacheListEnd {
        return
    }
    node.next.prev = node.prev
    if node == this.cacheList {
        this.cacheList = node.next
    } else {
        node.prev.next = node.next
    }
    this.cacheListEnd.next = node
    node.prev = this.cacheListEnd
    node.next = nil
    this.cacheListEnd = node
}

// add a new cache node to the end of the cache list
func (this *LRUCache) addNew(key int, value int) {
    newNode := CacheNode {
        key : key,
        value : value,
        prev : this.cacheListEnd,
        next : nil,
    }
    if this.cacheList == nil {
        this.cacheList = &newNode
    } else {
        this.cacheListEnd.next = &newNode
    }
    this.cacheListEnd = &newNode
    this.cacheMap[key] = &newNode
    if len(this.cacheMap) > this.capacity {
        delete(this.cacheMap, this.cacheList.key)
        this.cacheList.next.prev = nil
        this.cacheList = this.cacheList.next
    }
}
func (this *LRUCache) Get(key int) int {
    if this.capacity < 1 {
        return -1
    }
    node,exists := this.cacheMap[key]
    if !exists {
        return -1
    }
    this.moveToEnd(node)
    return node.value
}


func (this *LRUCache) Put(key int, value int)  {
    if this.capacity < 1 {
        return
    }
    node,exists := this.cacheMap[key]
    if exists {
        node.value = value
        this.moveToEnd(node)
    } else {
        this.addNew(key, value)
    }
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
