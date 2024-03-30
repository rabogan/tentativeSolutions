class LRUCache {
private:    
    int size{};
    list<int>lru;
    unordered_map<int,int>key_value;
    unordered_map<int,list<int>::iterator>key_iterator;
public:
    LRUCache(int capacity):size(capacity) {
        
    }
    
    int get(int key) {
        if(!key_value.count(key))
            return -1;
        updateLRU(key);
        return key_value[key];
    }
    
    void put(int key, int value) {
        if(key_value.size()==size && key_value.count(key)==0)
            evict();
        updateLRU(key);
        key_value[key] = value;
    }
    
    void updateLRU(int key){
        if(key_value.count(key))
            lru.erase(key_iterator[key]);
        lru.push_front(key);
        key_iterator[key] = lru.begin();
    }
    
    void evict(){
        key_value.erase(lru.back());
        key_iterator.erase(lru.back());
        lru.pop_back();
    }
};

/*
This can be done using C++ STL list as well!

The LRU Cache behind the scenes:
1)  We set things up so that the LRU is at the tail of the list, and the Most Recently Used at the head
Thus, we can access the LRU in O(1) time just by looking at the tail of the list!
2)  However, to avoid the O(N) time needed to search for specific nodes in a list, we'll also need
to use a hash map!  This way, we link the map's items (our keys) to the linked list nodes and/or their values
Thus, we can find an element in our LRU cache's doubly linked list in O(1) time - not O(N) time
Using two hash tables to separate our key_value and key_DLL_iterator is a good optmization
So, our LRU cache will need:
int size{};
list<int>lru;
unordered_map<int,int>key_value;
unordered_map<int,list<int>::iterator>key_iterator;

3)  The LRU Cache constructor
Very simple: we initialize the size variable with capacity

4)  The get function!
Firstly, as demanded in the instruction, if there is no key contained in our table, return -1
Otherwise, we need to UPDATE our LRU with the key ***(see section about that...)
Then, we return key_value[key] :)
***
(It's basically where - if it EXISTS!!! - we erase the iterator from our DLL (list<int>lru) using key_iterator[key])
(If it's doesn't exist, no worries...we push_front(key)...pushing the key to the front to the DLL)
Then we update the key_iterator like so:  key_iterator[key] = lru.begin();
***

5)  The put function!  (using key, value)
Here, we need to first check two things:
a) Is the DLL at full capacity?  b) AND is our key NOT included among the hash table or list?
If a and b are both true, we will need to EVICT!
b) In any case, we will update the LRU with a KEY
c) After that, we'll use key_value[key] = value; to update the key_value table!
N.B. key_iterator[key] = lru.begin() is in our key_iterator table...in updateLRU

6)  The updateLRU function!!!  (using a key!)
a)  First of all, we need to ERASE the element from the DLL
This uses the key_iterator value, like so:
lru.erase(key_iterator[key]);
b)  THEN, we need to push the key to the front of the DLL
lru.push_front(key);
c)  Finally, update the key_iterator table!
key_iterator[key] = value;

7)  The evict function!
a)  Remove the BACK element from both tables!  .erase(lru.back())
b)  Remove the LAST element in the DLL (lru.pop_back())
*/
