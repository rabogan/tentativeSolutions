import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        class ListNodeComp implements Comparator<ListNode> {
            @Override
            public int compare(ListNode n1, ListNode n2) {
                return n1.val - n2.val;
            }
        }

        PriorityQueue<ListNode> minHeap = new PriorityQueue<>(new ListNodeComp());

        for (ListNode node : lists) {
            if (node != null)
                minHeap.offer(node);
        }

        ListNode head = null;
        ListNode tail = null;

        while (!minHeap.isEmpty()) {
            ListNode cur = minHeap.poll();

            if (cur.next != null)
                minHeap.offer(cur.next);

            if (head == null) {
                head = tail = cur;
            } else {
                tail.next = cur;
                tail = tail.next;
            }
        }

        return head;
    }
}
