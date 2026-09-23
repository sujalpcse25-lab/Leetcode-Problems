class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total = 0;

        for (int num : nums)
            total += num;

        long long target = total - x;

        if (target < 0)
            return -1;

        if (target == 0)
            return nums.size();

        long long sum = 0;
        int left = 0;
        int longest = -1;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum > target && left <= right) {
                sum -= nums[left];
                left++;
            }

            if (sum == target) {
                longest = max(longest, right - left + 1);
            }
        }

        if (longest == -1)
            return -1;

        return nums.size() - longest;
    }
};