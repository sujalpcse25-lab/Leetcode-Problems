
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int maxDiff = 0;
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
        }

        vector<long long> freq(maxDiff + 1, 0);

        for (int i = 0; i < n; i++) {
            freq[diff[i]]++;
        }

        for (int i = maxDiff; i > 0 && k > 0; i--) {
            long long count = freq[i];
            long long reduce = min(count, k);

            freq[i] -= reduce;
            freq[i - 1] += reduce;
            k -= reduce;
        }

        long long ans = 0;

        for (int i = 1; i <= maxDiff; i++) {
            ans += freq[i] * i * i;
        }

        return ans;
    }
};
