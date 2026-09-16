class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1000000007;

        long long fact[2005];
        long long invFact[2005];

        fact[0] = 1;

        for (int i = 1; i <= n + k - 1; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[n + k - 1] = power(fact[n + k - 1], MOD - 2);

        for (int i = n + k - 2; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }

        long long ans = fact[n + k - 1];

        ans = ans * invFact[2 * k] % MOD;
        ans = ans * invFact[n - k - 1] % MOD;

        return ans;
    }

    long long power(long long a, long long b) {
        long long result = 1;

        while (b > 0) {
            if (b % 2 == 1) {
                result = result * a % 1000000007;
            }

            a = a * a % 1000000007;
            b /= 2;
        }

        return result;
    }
};