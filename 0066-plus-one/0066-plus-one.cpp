class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; // No carry, return the result
            }
            digits[i] = 0; // Set current digit to 0 and carry to the next
        }
        // If we are here, it means we had a carry from the most significant digit
        digits.insert(digits.begin(), 1); // Insert 1 at the beginning
        return digits;
    }
};
