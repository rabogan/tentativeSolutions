class FirstUnique {
    list<int>uniqueNumbers;
    unordered_map<int,list<int>::iterator>valueToNode;
public:
    FirstUnique(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            add(nums[i]);
    }
    
    int showFirstUnique() {
        if(!uniqueNumbers.empty())
            return uniqueNumbers.front();
        return -1;
    }
    
    void add(int value) {
        if(valueToNode.count(value)){
            if(valueToNode[value] != uniqueNumbers.end()){
                uniqueNumbers.erase(valueToNode[value]);
                valueToNode[value] = uniqueNumbers.end();
            }
        }else{
            uniqueNumbers.push_back(value);
            valueToNode[value] = --uniqueNumbers.end();
        }
    }
};

/*
SOLUTION:
To retrieve a unique number in O(1) time, we need to use a DLL or queue
One great combo here is a LINKED LIST that contains unique numbers (and only unique numbers)
and a HASH TABLE that maps the VALUE to the position in the LINKED LIST.
Essentially, if the VALUE is unique in the linked list, we map the value to its node
If the value is NOT unique in the linked list, we map the value to NULL instead!
Once again, if the value is duplicated, we erase the value from the linked list, and maps it's position in the map to null

1)  We use a DLL, (uniqueNumbers)
a) It maintains all unique values!
b) If we add a UNIQUE NUMBER, we must be able to add it to the back of the list
We do this IFF (!valueToNode.count(value))
c) If we add a NON-UNIQUE value, then it's more complicated...
i) Check if the non-unique value is still in the list.  Essentially, we do this by looking at whether the value has been marked as null in the hash table
ii)  If it's marked as null, then we don't need to deal with it, or worry about it.
That's why we use:
if(valueToNode[value]!=uniqueNumbers.end())
We're only dealing with removing the unique number if it hasn't been removed from the list, or marked as null in the map
iii)  If it's in the list, and the value is appearing for the 2nd time, we want to do an O(1) friendly indicator that it can't be considered!
if(valueToNode.count(value))   STEP 1
   if(valueToNode[value]!=uniqueNumbers.end())  STEP 2 (check it's not already 'nullified')
    {
      uniqueNumbers.erase(valueToNode[value]);  STEP 3:  remove the entry from the list
      valueToNode[value] = uniqueNumbers.end();  STEP 4:  nullify the value in the map :)
    }
That's the tough stuff done!

The adding is fairly rudimentary, iterating through the vector given, and using the add function

The showFirstUnique scrapes the first value from the 'front()' of the linked list we made - assuming the LL isn't EMPTY!
If it empty, return -1 as described!
*/
