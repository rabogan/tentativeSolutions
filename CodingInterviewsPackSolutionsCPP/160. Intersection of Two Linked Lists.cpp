class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *copy_A = headA;
		ListNode *copy_B = headB;
		while(copy_A != copy_B){
			if(copy_A == nullptr){
				copy_A = headB;
			}
			else{
				copy_A = copy_A->next;
			}
			if(copy_B == nullptr){
				copy_B = headA;
			}
			else{
				copy_B = copy_B -> next;
			}
		}
		return copy_A;
	}
};