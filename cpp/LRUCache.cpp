class LRUCache{
public:
    struct CacheNode {
        int key;
        int value;
        CacheNode(int k, int v) : key(k), value(v) {}
    };
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
    list<CacheNode> cacheList;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
        cacheMap.clear();
        cacheList.clear();
    }
    
    int get(int key) {
        unordered_map<int, list<CacheNode>::iterator>::iterator found = cacheMap.find(key);
        if (found == cacheMap.end()) return -1;
        cacheList.splice(cacheList.end(), cacheList, found->second);
        return cacheList.back().value;
    }
    
    void set(int key, int value) {
        unordered_map<int, list<CacheNode>::iterator>::iterator found = cacheMap.find(key);
        if (found != cacheMap.end()) {
            cacheList.splice(cacheList.end(), cacheList, found->second);
            cacheList.back().value = value;
            return;
        }
        if (cacheMap.size() == capacity){
            cacheMap.erase(cacheList.front().key);
            cacheList.pop_front();
        }
        CacheNode newNode(key, value);
        cacheList.push_back(newNode);
        cacheMap[key] = --cacheList.end();
    }
};
