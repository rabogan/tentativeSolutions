class Solution {
    public Node treeToDoublyList(Node root) {
        if (root == null)
            return null;

        Node[] dll = treeToDoublyLinkedTraversal(root);
        dll[0].left = dll[1];
        dll[1].right = dll[0];

        return dll[0];
    }

    private Node[] treeToDoublyLinkedTraversal(Node root) {
        if (root == null)
            return new Node[]{null, null};

        Node[] left = treeToDoublyLinkedTraversal(root.left);
        Node[] right = treeToDoublyLinkedTraversal(root.right);

        Node first = root;
        Node last = root;

        if (left[0] != null) {
            root.left = left[1];
            left[1].right = root;
            first = left[0];
        }

        if (right[0] != null) {
            root.right = right[0];
            right[0].left = root;
            last = right[1];
        }

        return new Node[]{first, last};
    }
}
