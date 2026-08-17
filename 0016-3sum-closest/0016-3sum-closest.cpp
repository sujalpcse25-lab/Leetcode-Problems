class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort the array to enable the two-pointer technique
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];
        
        // Fix the first element, then use two pointers for the rest
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // If this sum is closer to target, update closestSum
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                // Move pointers based on comparison with target
                if (currentSum < target) {
                    left++;
                } else if (currentSum > target) {
                    right--;
                } else {
                    // Exact match found, return immediately
                    return currentSum;
                }
            }
        }
        
        return closestSum;
    }
};