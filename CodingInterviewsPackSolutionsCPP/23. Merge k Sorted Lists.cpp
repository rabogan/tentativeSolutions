/*
Brute Force Solution:
Look at the Merge Two Sorted Linked Lists here:
https://leetcode.com/problems/merge-two-sorted-lists/
You could apply the technique to sort the first two lists into one big list...
...then compare the big list with list 3 in the vector
...then compare the even bigger list with list 4, and so on!
But, that's O(K*N) - there are better approaches!

Solution:
Better is to utilize a HEAP-based approach

Intuition:
In the other problem, we want to pick the smallest element from 2 lists!
In this, we want to pick the smallest element from K sources!
To do so efficiently, we extend the code/idea
1)  Add the lists into a MIN-HEAP (requires knowledge of comparator classes!)
1b) Assign your head and tail nodes now, then dive into the minHeap until it's empty!
2)  Select the MINIMUM item, add this node from its list to the answer.  We add it to the output LATER
3)  Firstly, REMOVE THE LIST of the minimum element from the min-heap (potentially temporarily)
3b) Remove the front item from the removed list
3c) Assuming the list has remaining nodes, add the freshly cut list into the heap again
4)  We'll use head and tail nodes to create our return
5a)  After grabbing the element, we check if a head has been created already
5b)  If not, assign HEAD and TAIL to our CURRENT node
5c)  Otherwise, simply link the previous TAIL to our CURRENT node, then assign CUR to the TAIL!
6)   Voila!  This approach is O(N log K)

Another approach involves D&C, but that's for another day - I need to master the COMPARATOR class and HEAPS

Comparator:
In our priority queue, we will compare the OBJECTS rather than integer values, so the usual greater<int> is out!
We create a class to compare listnodes, class listNodeComp!
This CLASS is NOT in the SOLUTION class, and the comparator function MUST BE PUBLIC!
1)Return an integer, and use operator()
int operator()(ListNode* l1, ListNode* l2)
2)We use
return l1->val > l2->val
Note the use of GREATER THAN!  This is because we want to add the minimum values into our minHeap!
The PRIORITY_QUEUE, of course, uses:
ListNode*, vector<ListNode*>, listNodeComp 
 */
class listNodeComp{
public:
    int operator()(ListNode* n1, ListNode* n2){
        return n1->val > n2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,listNodeComp>minHeap;
        
        int sz = lists.size();
        
        for(int i = 0; i < sz; i++){
            if(lists[i])
                minHeap.push(lists[i]);
        }
        
        ListNode* head = nullptr;
        ListNode* tail = head;
        
        while(!minHeap.empty()){
            ListNode* cur = minHeap.top();
            minHeap.pop();
            
            if(cur->next)
                minHeap.push(cur->next);
            
            if(!head)
                head = tail = cur;
            else{
                tail->next = cur;
                tail = tail->next;
            }
        }
        return head;
    }
};