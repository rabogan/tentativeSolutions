class Solution {
    private int[] LISmem;
    private int[] LDSmem;
    private int[] nums;

    public int minimumMountainRemovals(int[] nums) {
        int MAX = 1000 + 1;
        LISmem = new int[MAX];
        LDSmem = new int[MAX];
        this.nums = nums;

        Arrays.fill(LISmem, -1);
        Arrays.fill(LDSmem, -1);

        int n = nums.length;
        int mountains = 0;

        for (int i = 0; i < n; i++) {
            if (LIS(i) == 1 || LDS(i) == 1) {
                continue;
            }

            int cur = LIS(i) + LDS(i) - 1;
            mountains = Math.max(mountains, cur);
        }

        return n - mountains;
    }

    private int LIS(int index) {
        if (index == -1) {
            return 0;
        }

        if (LISmem[index] != -1) {
            return LISmem[index];
        }

        int ret = 0;
        for (int prev = index - 1; prev >= 0; prev--) {
            if (nums[prev] < nums[index]) {
                ret = Math.max(ret, LIS(prev));
            }
        }

        ret += 1;
        LISmem[index] = ret;
        return ret;
    }

    private int LDS(int index) {
        if (index >= nums.length) {
            return 0;
        }

        if (LDSmem[index] != -1) {
            return LDSmem[index];
        }

        int ret = 0;
        for (int next = index + 1; next < nums.length; next++) {
            if (nums[index] > nums[next]) {
                ret = Math.max(ret, LDS(next));
            }
        }

        ret += 1;
        LDSmem[index] = ret;
        return ret;
    }
}
