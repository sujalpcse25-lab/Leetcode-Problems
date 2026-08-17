class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; i++) {
            // skip duplicates for first number
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            for (int j = i + 1; j < n - 2; j++) {
                // skip duplicates for second number
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                
                long long twoSumTarget = (long long)target - nums[i] - nums[j];
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long sum = (long long)nums[left] + nums[right];
                    if (sum == twoSumTarget) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // skip duplicates for left pointer
                        while (left < right && nums[left] == nums[left+1]) left++;
                        // skip duplicates for right pointer
                        while (left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    } else if (sum < twoSumTarget) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};