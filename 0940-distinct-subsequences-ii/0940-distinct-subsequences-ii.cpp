class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        long long dp[26] = {0};

        for (char c : s) {
            int index = c - 'a';

            long long sum = 0;

            for (int i = 0; i < 26; i++) {
                sum = (sum + dp[i]) % MOD;
            }

            dp[index] = (sum + 1) % MOD;
        }

        long long ans = 0;

        for (int i = 0; i < 26; i++) {
            ans = (ans + dp[i]) % MOD;
        }

        return (int)ans;
    }
};