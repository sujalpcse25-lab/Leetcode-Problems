class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        // Find min and max
        int minVal = nums[0], maxVal = nums[0];
        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }
        
        if (minVal == maxVal) return 0;
        
        // Bucket size: minimum possible max gap
        int bucketSize = max(1, (maxVal - minVal) / (n - 1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;
        
        vector<pair<int,int>> buckets(bucketCount, {INT_MAX, INT_MIN}); // {min, max}
        vector<bool> used(bucketCount, false);
        
        // Distribute numbers into buckets
        for (int num : nums) {
            int idx = (num - minVal) / bucketSize;
            buckets[idx].first = min(buckets[idx].first, num);
            buckets[idx].second = max(buckets[idx].second, num);
            used[idx] = true;
        }
        
        // Compute max gap between consecutive non-empty buckets
        int maxGap = 0, prevMax = minVal;
        for (int i = 0; i < bucketCount; i++) {
            if (!used[i]) continue;
            maxGap = max(maxGap, buckets[i].first - prevMax);
            prevMax = buckets[i].second;
        }
        
        return maxGap;
    }
};