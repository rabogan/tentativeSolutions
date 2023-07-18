public class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> sumMap = new HashMap<>();
        int sz = nums.length;
        for (int index = 0; index < sz; index++) {
            int remainder = target - nums[index];
            if (sumMap.containsKey(remainder))
                return new int[]{sumMap.get(remainder), index};
            
            sumMap.put(nums[index], index);
        }
        return new int[]{-1, -1};
    }
}