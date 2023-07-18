class AllOne {
    struct bucket{
        int val;
        unordered_set<string>keys;
    };
    
    list<bucket>buckets;
    unordered_map<string,list<bucket>::iterator>hash;
    
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        if(!hash.count(key)){
            if(buckets.empty() || buckets.back().val != 1){
                auto newBucket = buckets.insert(buckets.end(),{1,{key}});
                hash[key] = newBucket;
            }
            else{
                auto newBucket = --buckets.end();
                newBucket->keys.insert(key);
                hash[key] = newBucket;
            }
        }
        else{
            auto curBucket = hash[key];
            auto prevBucket = --hash[key];
            if(prevBucket->val != curBucket->val+1 || curBucket ==buckets.begin()){
                auto newBucket = buckets.insert(curBucket,{curBucket->val+1,{key}});
                hash[key] = newBucket;
            }
            else{
                prevBucket->keys.insert(key);
                hash[key] = prevBucket;
            }
            curBucket->keys.erase(key);
            if(curBucket->keys.empty())
                buckets.erase(curBucket);
        }
    }
    
    void dec(string key) {
        if(!hash.count(key))
            return;
        
        auto curBucket = hash[key];
        if(curBucket->val==1){
            curBucket->keys.erase(key);
            if(curBucket->keys.empty()){
                buckets.erase(curBucket);
            }
            hash.erase(key);
            return;
        }
        auto nextBucket = ++hash[key];
        if(nextBucket==buckets.end()||nextBucket->val != curBucket->val-1){
            auto newBucket = buckets.insert(nextBucket,{curBucket->val-1,{key}});
            hash[key] = newBucket;
        }
        else{
            nextBucket->keys.insert(key);
            hash[key] = nextBucket;
        }
        curBucket->keys.erase(key);
        if(curBucket->keys.empty())
            buckets.erase(curBucket);
    }
    
    string getMaxKey() {
        return buckets.empty()?"":*(buckets.begin()->keys.begin());
    }
    
    string getMinKey() {
        return buckets.empty()? "": *(buckets.rbegin()->keys.begin());
    }
};
