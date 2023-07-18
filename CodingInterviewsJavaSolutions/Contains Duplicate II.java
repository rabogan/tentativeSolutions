class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer> myMap = new HashMap<>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (myMap.containsKey(nums[i]) && i - myMap.get(nums[i]) <= k) {
                return true;
            }
            myMap.put(nums[i], i);
        }
        return false;
    }
}
