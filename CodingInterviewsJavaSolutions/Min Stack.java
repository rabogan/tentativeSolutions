class MinStack {
    private Stack<Integer> data;
    private Stack<Integer> mnStack;

    public MinStack() {
        data = new Stack<>();
        mnStack = new Stack<>();
    }

    public void push(int val) {
        data.push(val);
        if (mnStack.isEmpty() || val <= mnStack.peek()) {
            mnStack.push(val);
        }
    }

    public void pop() {
        if (mnStack.peek().equals(data.peek())) {
            mnStack.pop();
        }
        data.pop();
    }

    public int top() {
        return data.peek();
    }

    public int getMin() {
        return mnStack.peek();
    }
}
