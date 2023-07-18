class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode lessThan = new ListNode(0);
        ListNode remaining = new ListNode(0);

        ListNode before = lessThan;
        ListNode after = remaining;

        while (head != null) {
            if (head.val < x) {
                before.next = head;
                before = head;
            } else {
                after.next = head;
                after = head;
            }
            head = head.next;
        }

        before.next = remaining.next;
        after.next = null;
        head = lessThan.next;

        return head;
    }
}
