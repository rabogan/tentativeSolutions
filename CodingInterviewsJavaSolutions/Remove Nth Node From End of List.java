class Solution {
    public int length(ListNode head) {
        int count = 0;
        while (head != null) {
            count++;
            head = head.next;
        }
        return count;
    }

    public ListNode getNth(ListNode head, int n) {
        int count = 0;
        ListNode cur = head;
        while (cur != null) {
            count++;
            if (count == n) {
                return cur;
            }
            cur = cur.next;
        }
        return null;
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        int len = length(head);
        head = new ListNode(-1, head);

        ListNode prev = getNth(head, len - n + 1);
        ListNode toRemove = prev.next;

        prev.next = prev.next.next;
        toRemove = null;

        toRemove = head;
        head = head.next;

        toRemove = null;
        return head;
    }
}
