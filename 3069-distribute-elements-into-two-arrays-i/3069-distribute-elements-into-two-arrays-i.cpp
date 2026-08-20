class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]); // First operation
        arr2.push_back(nums[1]); // Second operation
        
        for (int i = 2; i < nums.size(); ++i) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }
        
        arr1.insert(arr1.end(), arr2.begin(), arr2.end()); // Concatenate arr2 to arr1
        return arr1;
    }
};
