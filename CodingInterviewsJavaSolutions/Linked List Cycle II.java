public class Solution {
    public ListNode transection(ListNode node) {
        ListNode tortoise = node;
        ListNode hare = node;
        while (hare != null && hare.next != null) {
            tortoise = tortoise.next;
            hare = hare.next.next;
            if (tortoise == hare) {
                return tortoise;
            }
        }
        return null;
    }

    public ListNode detectCycle(ListNode head) {
        if (head == null) {
            return head;
        }

        ListNode trans = transection(head);
        if (trans == null) {
            return trans;
        }

        while (trans != head) {
            head = head.next;
            trans = trans.next;
        }
        return trans;
    }
}
