class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        Node result = null;
        Node new_result = null;
        HashMap<Node, Node> my_map = new HashMap<>();

        // First pass: Create new nodes and map original nodes to new nodes
        for (Node temp_head = head; temp_head != null; temp_head = temp_head.next) {
            Node new_node = new Node(temp_head.val);
            new_node.random = temp_head.random;
            my_map.put(temp_head, new_node);

            if (result == null) {
                result = new_node;
            } else {
                new_result.next = new_node;
            }

            new_result = new_node;
        }

        // Second pass: Adjust random pointers using the map
        for (Node temp_head = result; temp_head != null; temp_head = temp_head.next) {
            temp_head.random = my_map.get(temp_head.random);
        }

        return result;
    }
}
