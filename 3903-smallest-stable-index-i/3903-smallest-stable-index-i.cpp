class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        int right[n];

        // Find minimum from i to n-1
        right[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(nums[i], right[i + 1]);
        }

        // Find maximum from 0 to i
        int left = 0;

        for (int i = 0; i < n; i++) {
            left = max(left, nums[i]);

            if (left - right[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};