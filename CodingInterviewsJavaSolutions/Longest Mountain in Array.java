class Solution {
    public int longestMountain(int[] arr) {
        int sz = arr.length;
        int result = 0;
        int up = 0;
        int down = 0;
        int index = 1;
        
        while (index < sz) {
            if ((down != 0 && arr[index - 1] < arr[index]) || arr[index - 1] == arr[index]) {
                up = down = 0;
            }
            
            if (arr[index - 1] < arr[index]) {
                up += 1;
            } else if (arr[index - 1] > arr[index]) {
                down += 1;
            } else {
                up = 0;
            }
            
            if (up != 0 && down != 0) {
                result = Math.max(result, up + down + 1);
            }
            
            index += 1;
        }
        
        return result;
    }
}
