class FirstUnique {
    private Map<Integer, Integer> valueToNode;
    private List<Integer> uniqueNumbers;

    public FirstUnique(int[] nums) {
        valueToNode = new LinkedHashMap<>();
        uniqueNumbers = new ArrayList<>();
        for (int num : nums) {
            add(num);
        }
    }

    public int showFirstUnique() {
        if (!uniqueNumbers.isEmpty()) {
            return uniqueNumbers.get(0);
        }
        return -1;
    }

    public void add(int value) {
        if (valueToNode.containsKey(value)) {
            if (valueToNode.get(value) != null) {
                uniqueNumbers.remove(valueToNode.get(value));
                valueToNode.put(value, null);
            }
        } else {
            uniqueNumbers.add(value);
            valueToNode.put(value, value);
        }
    }
}
