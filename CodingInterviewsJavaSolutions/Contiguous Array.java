class Solution {
    public int findMaxLength(int[] nums) {
        int cumSum = 0;
        HashMap<Integer, Integer> myMap = new HashMap<>();
        myMap.put(0, -1);
        int sz = nums.length;
        int result = 0;

        for (int i = 0; i < sz; i++) {
            if (nums[i] == 0)
                cumSum--;
            else
                cumSum++;

            if (!myMap.containsKey(cumSum))
                myMap.put(cumSum, i);
            else
                result = Math.max(result, i - myMap.get(cumSum));
        }
        return result;
    }
}
