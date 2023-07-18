import java.util.*;

class LRUCache {
    private int size;
    private List<Integer> lru;
    private Map<Integer, Integer> key_value;
    private Map<Integer, Integer> key_iterator;

    public LRUCache(int capacity) {
        size = capacity;
        lru = new ArrayList<>();
        key_value = new HashMap<>();
        key_iterator = new HashMap<>();
    }
    
    public int get(int key) {
        if (!key_value.containsKey(key))
            return -1;
        updateLRU(key);
        return key_value.get(key);
    }
    
    public void put(int key, int value) {
        if (key_value.size() == size && !key_value.containsKey(key))
            evict();
        updateLRU(key);
        key_value.put(key, value);
    }
    
    private void updateLRU(int key) {
        if (key_value.containsKey(key))
            lru.remove(key_iterator.get(key));
        lru.add(0, key);
        key_iterator.put(key, lru.get(0));
    }
    
    private void evict() {
        int keyToRemove = lru.get(lru.size() - 1);
        key_value.remove(keyToRemove);
        key_iterator.remove(keyToRemove);
        lru.remove(lru.size() - 1);
    }
}
