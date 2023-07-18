class Solution {
public:
    int length(ListNode* head){
        int count = 0;
        for(; head; head = head->next)
            count++;
        return count;
    }
    
    ListNode* getNth(ListNode* head, int n){
        int count = 0;
        for(ListNode*cur = head; cur; cur = cur->next){
            count++;
            if(count==n)
                return cur;
        }
        return nullptr;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        head = new ListNode(-1,head);
        
        ListNode*prev = getNth(head,len-n+1);
        ListNode*toRemove = prev->next;
        
        prev->next = prev->next->next;
        delete toRemove;
        
        toRemove = head;
        head = head->next;
        
        delete toRemove;
        return head;
    }
};