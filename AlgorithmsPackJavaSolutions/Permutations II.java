class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Set<List<Integer>> filterSet = new HashSet<>();
        backtrack(nums, 0, filterSet);
        for (List<Integer> permutation : filterSet) {
            result.add(permutation);
        }
        return result;
    }

    private void backtrack(int[] nums, int index, Set<List<Integer>> filterSet) {
        if (index == nums.length) {
            List<Integer> permutation = new ArrayList<>();
            for (int num : nums) {
                permutation.add(num);
            }
            filterSet.add(permutation);
            return;
        }

        for (int i = index; i < nums.length; i++) {
            swap(nums, i, index);
            backtrack(nums, index + 1, filterSet);
            swap(nums, i, index);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
