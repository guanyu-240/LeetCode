public class LRUCache {
    class CacheNode{
        int key;
        int value;
        CacheNode prev;
        CacheNode next;
        CacheNode(int key, int value, CacheNode prev, CacheNode next) {
            this.key = key;
            this.value = value;
            this.prev = prev;
            this.next = next;
        }
    }
    
    private HashMap<Integer, CacheNode>cache;
    private CacheNode cacheList;
    private CacheNode lastPtr;
    private int capacity;
    
    public LRUCache(int capacity) {
        this.capacity = Math.max(1, capacity);
        cache = new HashMap<Integer, CacheNode>();
        cacheList = new CacheNode(-1, -1, null, null);
        lastPtr = cacheList;
    }
    
    private void addToLast(CacheNode cnode) {
        if (cnode == cacheList || cnode == lastPtr) return;
        lastPtr.next = cnode;
        if (cnode.prev != null) {
            cnode.prev.next = cnode.next;
            cnode.next.prev = cnode.prev;
        }
        cnode.prev = lastPtr;
        cnode.next = null;
        lastPtr = cnode;
    }
    
    private CacheNode removeFirst(){
        if (cacheList.next == null) return null;
        CacheNode first = cacheList.next;
        cacheList.next = first.next;
        if (first.next != null) {
            first.next.prev = cacheList;
        }
        return first;
    }
    public int get(int key) {
        CacheNode cnode = cache.get(key);
        if (cnode == null) return -1;
        addToLast(cnode);
        return cnode.value;
    }

    public void set(int key, int value) {
        CacheNode cnode = cache.get(key);
        if (cnode == null) {
            cnode = new CacheNode(key, value, null, null);
            if (cache.size() == capacity) {
                CacheNode toRemove = removeFirst();
                if (toRemove == null) return;
                cache.remove(toRemove.key);
            }
            cache.put(key, cnode);
        }
        else {
            cnode.value = value;
        }
        addToLast(cnode);
    }
}
