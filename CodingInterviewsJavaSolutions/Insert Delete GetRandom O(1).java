class RandomizedSet {
    private List<Integer> values;
    private Map<Integer, Integer> value_vectorIndex;

    public RandomizedSet() {
        values = new ArrayList<>();
        value_vectorIndex = new HashMap<>();
    }

    public boolean insert(int val) {
        if (value_vectorIndex.containsKey(val))
            return false;

        value_vectorIndex.put(val, values.size());
        values.add(val);
        return true;
    }

    public boolean remove(int val) {
        if (!value_vectorIndex.containsKey(val))
            return false;

        int idx = value_vectorIndex.get(val);
        Collections.swap(values, idx, values.size() - 1);
        value_vectorIndex.put(values.get(idx), idx);
        value_vectorIndex.remove(values.get(values.size() - 1));
        values.remove(values.size() - 1);

        return true;
    }

    public int getRandom() {
        Random rand = new Random();
        return values.get(rand.nextInt(values.size()));
    }
}
