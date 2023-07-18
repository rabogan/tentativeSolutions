class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> ret = new ArrayList<>();
        
        for (int i = 0; i <= n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                
                if (total == 0) {
                    ret.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    
                    left++;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    
                    right--;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                } else if (total > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        
        return ret;
    }
}
