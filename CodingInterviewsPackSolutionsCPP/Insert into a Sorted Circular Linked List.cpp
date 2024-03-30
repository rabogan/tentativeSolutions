class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head){
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        
        Node* cur = head;
        do{
            int first = cur->val;
            int second = cur->next->val;
            
            if(first<=insertVal && insertVal<=second)
                break;
            
            if(first > second){
                if(first<=insertVal||insertVal<=second)
                    break;
            }
            cur = cur->next;
        }while(cur!=head);
        
        cur->next = new Node(insertVal,cur->next);
        return head;
    }
};

/*
SOLUTION THOUGHT PROCESS:
1) First of all, if we have an empty list (i.e. no head), 
we have to create our circular LL
If we have any nodes at all, then we need a way of inserting 
our value into them.  Take a copy of the given head.
2) Where to insert? Well, there are several potential 
insertion cases! Let's take two consecutive nodes, A and B:
a) If A <= value <= B
Then we need to insert our value after A.
b) However, there is a special case call the FLIP POINT
The flip point occurs where A>B
If we have a flip point, then we have 2 potential 
insertions for it
i) (If A<=value) if the value is larger, it means the 
value is larger than the largest value in the sequence!
We'll want to stick our value directly after A, and before B
ii) (If value<=B) if the value is smaller than B, it means 
the value is going to be the SMALLEST in the sequence
AND, we'll want to stick our value directly BEFORE B, 
and after A!

So, we have 3 criteria where we'll want to insert after A!
1) A<=value<=B
2) A > B && value>=A
3) A > B && value<=B
We'll iterate through using our do-while loop, until the 
criteria are met

If nothing is met, it means we have a simple increasing 
circular linked list, in the style of 1->2->3->4->5
After we find our 'A' (or wherever cur happens to finish), 
we need to insert the value correctly!
cur->next = new Node(val,cur->next);
return head;
*/
