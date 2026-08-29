class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        sort(a.begin(), a.end());

        int start = 0;

        while (start < n) {
            int end = start;

            while (end + 1 < n && a[end + 1].first - a[end].first <= limit) {
                end++;
            }

            vector<int> values;
            vector<int> indices;

            for (int i = start; i <= end; i++) {
                values.push_back(a[i].first);
                indices.push_back(a[i].second);
            }

            sort(indices.begin(), indices.end());

            for (int i = 0; i < values.size(); i++) {
                nums[indices[i]] = values[i];
            }

            start = end + 1;
        }

        return nums;
    }
};