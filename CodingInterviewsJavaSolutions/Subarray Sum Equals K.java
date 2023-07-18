class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> myMap = new HashMap<>();
        myMap.put(0, 1);
        int sz = nums.length;
        int result = 0;
        int prefixSum = 0;
        for (int i = 0; i < sz; i++) {
            prefixSum += nums[i];
            if (myMap.containsKey(prefixSum - k)) {
                result += myMap.get(prefixSum - k);
            }
            myMap.put(prefixSum, myMap.getOrDefault(prefixSum, 0) + 1);
        }
        return result;
    }
}
