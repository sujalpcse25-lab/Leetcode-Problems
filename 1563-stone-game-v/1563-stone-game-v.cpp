class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefixSum(n + 1, 0);
        
        // Calculate prefix sums
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        }

        // dp[i][j] will store the maximum score Alice can achieve from stoneValue[i] to stoneValue[j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Fill the dp table
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                // Try all possible divisions
                for (int k = i; k < j; ++k) {
                    int leftSum = prefixSum[k + 1] - prefixSum[i]; // sum of left row
                    int rightSum = prefixSum[j + 1] - prefixSum[k + 1]; // sum of right row
                    if (leftSum < rightSum) {
                        dp[i][j] = max(dp[i][j], dp[i][k] + leftSum);
                    } else if (leftSum > rightSum) {
                        dp[i][j] = max(dp[i][j], dp[k + 1][j] + rightSum);
                    } else {
                        dp[i][j] = max(dp[i][j], max(dp[i][k] + leftSum, dp[k + 1][j] + rightSum));
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
