class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long l = 1, r = 1LL * coins[0] * k;

        auto count = [&](long long x) {
            long long res = 0;
            int n = coins.size();

            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                int bits = 0;

                for (int i = 0; i < n; i++)
                    if (mask & (1 << i)) {
                        bits++;
                        lcm = lcm / gcd(lcm, (long long)coins[i]) * coins[i];
                        if (lcm > x) break;
                    }

                if (lcm <= x)
                    res += (bits & 1) ? x / lcm : -x / lcm;
            }
            return res;
        };

        while (l < r) {
            long long m = (l + r) / 2;
            if (count(m) >= k) r = m;
            else l = m + 1;
        }

        return l;
    }
};