class LFUCache {
    int capacity{};
    int minFreq{};
    
    unordered_map<int,int>keyValue;
    unordered_map<int,int>keyFreq;
    unordered_map<int,list<int>>freqKeylist;
    unordered_map<int,list<int>::iterator>keyIterator;
public:
    LFUCache(int capacity):capacity(capacity) {
        
    }
    
    int get(int key) {
        if(!keyValue.count(key))
            return -1;
        
        updateLRU(key);
        return keyValue[key];
    }
    
    void put(int key, int value) {
        if(capacity==0)
            return;
        if(capacity==keyValue.size() && keyValue.count(key)==0)
            evict();
        if(keyValue.count(key)){
            updateLRU(key);
            keyValue[key] = value;
        }
        else{
            keyValue[key] = value;
            keyFreq[key] = 1;
            freqKeylist[1].push_front(key);
            keyIterator[key] = freqKeylist[1].begin();
            minFreq = 1;
        }
    }
    
    void updateLRU(int key){
        freqKeylist[keyFreq[key]].erase(keyIterator[key]);
        keyFreq[key]++;
        freqKeylist[keyFreq[key]].push_front(key);
        keyIterator[key] = freqKeylist[keyFreq[key]].begin();
        
        if(freqKeylist[minFreq].empty()){
            freqKeylist.erase(minFreq);
            minFreq++;
        }
    }
    
    void evict(){
        int lfu = freqKeylist[minFreq].back();
        freqKeylist[minFreq].pop_back();
        keyValue.erase(lfu);
        keyFreq.erase(lfu);
        keyIterator.erase(lfu);
    }
};
