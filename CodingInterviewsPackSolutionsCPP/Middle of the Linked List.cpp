class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* tortoise = head;
        ListNode* hare = head;

        while(hare && hare->next){
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        return tortoise;
    }
};
