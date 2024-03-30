class RandomizedSet {
    vector<int>values;
    unordered_map<int,int>value_vectorIndex;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(value_vectorIndex.count(val))
            return false;
        
        value_vectorIndex[val] = values.size();
        values.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!value_vectorIndex.count(val))
            return false;
        
        int idx = value_vectorIndex[val];
        swap(values[idx],values.back());
        value_vectorIndex[values[idx]] = idx;
        value_vectorIndex.erase(values.back());
        values.pop_back();
        
        return true;
    }
    
    int getRandom() {
        return values[rand()%values.size()];
    }
};

/*
SOLUTION:
We need a way of storing our values, but we must have O(1) 
access.  The Linked List doesn't allow for O(1) access and 
removal randomly.  The vector is best, as we can access it 
randomly easily.  We also need a hash table mapping value
to the vector index!

INSERT:
The insert function brings in a value in O(1)
a) First, we need to check if it's already in the vector.
We use value_vectorIndex.count(val) to do so (return false 
if need be)
b) If it's new, then we need to add it.  First of all, 
map the value to the vectorIndex in the hash table
c) Next, add the value to the values vector. (Return true)

REMOVE:
This removes a val in O(1)
a) Again, we need to check if the value is in the vector. 
The hash table allows in O(1).  Return false if necessary
b) For easy removals from a vector, we need to do LAZY 
DELETION in O(1).
bii) This is ONLY okay if the order doesn't matter!
c) So, to achieve this, we need to grab the index of the 
value (use the hash table)
d) Then, we swap the BACK of the vector with values[index]. 
Don't 'pop' prematurely!!!
e) We update the hash table, so that the previous 'back' 
element is now like value_vectorIndex[values[idx]] = idx
f) Then, we REMOVE the value.back() from the hash table
g) Finally, pop() from values and return true!

GET RANDOM:
This returns a random number in O(1)
simple as!  return values[rand()%values.size()];
*/
