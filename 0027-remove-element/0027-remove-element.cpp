class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;  // k tracks the position for the next valid element
        
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[k] = nums[j];
                k++;
            }
        }
        
        return k;
    }
};