class Solution {
public:
    int numOfWays(vector<int>& nums) {
        const long long MOD = 1000000007;
        int n = nums.size();

        vector<vector<long long>> comb(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        function<long long(vector<int>&)> solve = [&](vector<int>& arr) -> long long {
            int m = arr.size();

            if (m <= 2) return 1;

            vector<int> left, right;

            for (int i = 1; i < m; i++) {
                if (arr[i] < arr[0])
                    left.push_back(arr[i]);
                else
                    right.push_back(arr[i]);
            }

            long long ways = comb[m - 1][left.size()];
            ways = ways * solve(left) % MOD;
            ways = ways * solve(right) % MOD;

            return ways;
        };

        return (solve(nums) - 1 + MOD) % MOD;
    }
};