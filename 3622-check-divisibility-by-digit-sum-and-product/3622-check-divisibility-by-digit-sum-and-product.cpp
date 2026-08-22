class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProduct = 1;
        int temp = n;

        // Calculate digit sum and product
        while (temp > 0) {
            int digit = temp % 10;
            digitSum += digit;
            digitProduct *= digit;
            temp /= 10;
        }

        // Check divisibility
        return (n % (digitSum + digitProduct) == 0);
    }
};
