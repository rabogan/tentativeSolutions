class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* tortoise = head;
        ListNode* hare = head;
        
        while(hare && hare->next){
            tortoise = tortoise->next;
            hare = hare->next->next;
            
            if(tortoise==hare)
                return true;
        }
        return false;
    }
};
