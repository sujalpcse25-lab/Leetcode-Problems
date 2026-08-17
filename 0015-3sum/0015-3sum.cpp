class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());  // Step 1: Sort to enable two-pointer approach
        
        // Step 2: Fix the first element (anchor)
        for (int i = 0; i < nums.size() - 2; i++) {
            // Skip duplicate values for the anchor to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Step 3: Two pointers for the remaining two numbers
            int left = i + 1;
            int right = nums.size() - 1;
            int target = -nums[i];  // We need nums[left] + nums[right] = -nums[i]
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the left pointer
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // Skip duplicates for the right pointer
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    left++;
                    right--;
                }
                else if (sum < target) {
                    left++;   // Sum too small, move left pointer right
                }
                else {
                    right--;  // Sum too large, move right pointer left
                }
            }
        }
        
        return result;
    }
};