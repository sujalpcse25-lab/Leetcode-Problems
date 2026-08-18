#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        int n = nums.size();

        // Special cases
        if (k == 1) {
            // Return the largest element that occurs exactly once
            int maxNum = -1;
            for (int num : nums) {
                if (count(nums.begin(), nums.end(), num) == 1) {
                    maxNum = max(maxNum, num);
                }
            }
            return maxNum;
        }

        if (k == n) {
            // Return the largest element in nums
            return *max_element(nums.begin(), nums.end());
        }

        // General case for 1 < k < n
        // Count occurrences of each number in all subarrays of size k
        for (int i = 0; i <= n - k; ++i) {
            for (int j = 0; j < k; ++j) {
                countMap[nums[i + j]]++;
            }
        }

        // Find the largest integer that appears exactly once
        int largestAlmostMissing = -1;
        for (const auto& entry : countMap) {
            if (entry.second == 1) {
                largestAlmostMissing = max(largestAlmostMissing, entry.first);
            }
        }

        return largestAlmostMissing;
    }
};
