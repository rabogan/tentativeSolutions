class Solution {
public:
    ListNode* transection(ListNode* node){
        ListNode* tortoise = node;
        ListNode* hare = node;
        while(hare && hare->next){
            tortoise = tortoise->next;
            hare = hare->next->next;
            if(tortoise==hare)
                return tortoise;
        }
        return nullptr;
    }

    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return head;
        
        ListNode* trans = transection(head);
        if(!trans)
            return trans;

        while(trans!=head){
            head = head->next;
            trans = trans->next;
        }
        return trans;
    }
};
