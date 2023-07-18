/*

In Java, there is no built-in equivalent to sort(nums.rbegin(), nums.rend()) in C++, which sorts the elements in reverse order. However, you can achieve the same effect by reversing the array after sorting it in ascending order using Arrays.sort().

This code sorts the array in ascending order using Arrays.sort(nums) and then reverses the array using the reverse() helper method. The rest of the logic remains the same as the C++ code.
*/

class Solution {
    public int reductionOperations(int[] nums) {
        Arrays.sort(nums);
        reverse(nums);

        int operations = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1]) {
                operations += i;
            }
        }

        return operations;
    }

    private void reverse(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        while (left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
}