class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessThan = new ListNode(0);
        ListNode* remaining = new ListNode(0);

        ListNode* before = lessThan;
        ListNode* after = remaining;

        while(head){
            if(head->val < x){
                before->next = head;
                before = head;
            }else{
                after->next = head;
                after = head;
            }
            head = head->next;
        }

        before->next = remaining->next;
        after->next = nullptr;
        head = lessThan->next;
        delete lessThan;
        delete remaining;

        return head;
    }
};
