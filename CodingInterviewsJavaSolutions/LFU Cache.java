class LFUCache {
    private int capacity;
    private int minFreq;
    private Map<Integer, Integer> keyValue;
    private Map<Integer, Integer> keyFreq;
    private Map<Integer, List<Integer>> freqKeylist;
    private Map<Integer, Integer> keyIterator;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.minFreq = 0;
        this.keyValue = new HashMap<>();
        this.keyFreq = new HashMap<>();
        this.freqKeylist = new HashMap<>();
        this.keyIterator = new HashMap<>();
    }

    public int get(int key) {
        if (!keyValue.containsKey(key)) {
            return -1;
        }
        updateLRU(key);
        return keyValue.get(key);
    }

    public void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        if (capacity == keyValue.size() && !keyValue.containsKey(key)) {
            evict();
        }
        if (keyValue.containsKey(key)) {
            updateLRU(key);
            keyValue.put(key, value);
        } else {
            keyValue.put(key, value);
            keyFreq.put(key, 1);
            freqKeylist.putIfAbsent(1, new LinkedList<>());
            freqKeylist.get(1).add(0, key);
            keyIterator.put(key, freqKeylist.get(1).get(0));
            minFreq = 1;
        }
    }

    private void updateLRU(int key) {
        freqKeylist.get(keyFreq.get(key)).remove(Integer.valueOf(keyIterator.get(key)));
        keyFreq.put(key, keyFreq.get(key) + 1);
        int freq = keyFreq.get(key);
        freqKeylist.putIfAbsent(freq, new LinkedList<>());
        freqKeylist.get(freq).add(0, key);
        keyIterator.put(key, freqKeylist.get(freq).get(0));

        if (freqKeylist.get(minFreq).isEmpty()) {
            freqKeylist.remove(minFreq);
            minFreq++;
        }
    }

    private void evict() {
        int lfu = freqKeylist.get(minFreq).remove(freqKeylist.get(minFreq).size() - 1);
        keyValue.remove(lfu);
        keyFreq.remove(lfu);
        keyIterator.remove(lfu);
    }
}
