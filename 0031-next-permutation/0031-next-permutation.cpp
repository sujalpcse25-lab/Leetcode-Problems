#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find the breakpoint (first index i where nums[i] < nums[i+1])
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        // If a breakpoint exists, perform swap and suffix reversal
        if (i >= 0) {
            // Step 2: Find the smallest element to the right that's larger than nums[i]
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        
        // Step 3: Reverse the suffix (or the whole array if no breakpoint found)
        reverse(nums.begin() + i + 1, nums.end());
    }
};