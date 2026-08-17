class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int k = 1;  // position of last unique element (starts at index 0)
        
        for (int j = 1; j < n; j++) {
            if (nums[j] != nums[k - 1]) {
                nums[k] = nums[j];
                k++;
            }
        }
        return k;
    }
};