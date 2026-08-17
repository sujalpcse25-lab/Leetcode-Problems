class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        
        // Find the first occurrence
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        // After this loop, lo is the first position where nums[lo] >= target
        if (lo < nums.size() && nums[lo] == target) {
            result[0] = lo;
        } else {
            return result;  // target not found
        }
        
        // Find the last occurrence
        lo = 0;
        hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        // After this loop, hi is the last position where nums[hi] <= target
        result[1] = hi;
        
        return result;
    }
};