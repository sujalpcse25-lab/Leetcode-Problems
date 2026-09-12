class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end(),
             [](auto &x, auto &y) {
                 if (x[1] != y[1])
                     return x[1] < y[1];
                 return x[0] < y[0];
             });

        vector<int> ends(n);

        for (int i = 0; i < n; i++) {
            ends[i] = a[i][1];
        }

        vector<vector<long long>> dp(
            n + 1, vector<long long>(5, 0)
        );

        vector<vector<vector<int>>> ans(
            n + 1, vector<vector<int>>(5)
        );

        for (int i = 1; i <= n; i++) {
            int start = a[i - 1][0];
            int weight = a[i - 1][2];
            int idx = a[i - 1][3];

            int prev = lower_bound(
                ends.begin(),
                ends.end(),
                start
            ) - ends.begin();

            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];
                ans[i][k] = ans[i - 1][k];

                long long score =
                    dp[prev][k - 1] + weight;

                vector<int> temp = ans[prev][k - 1];
                temp.push_back(idx);

                sort(temp.begin(), temp.end());

                if (score > dp[i][k]) {
                    dp[i][k] = score;
                    ans[i][k] = temp;
                }
                else if (score == dp[i][k] &&
                         temp < ans[i][k]) {
                    ans[i][k] = temp;
                }
            }
        }

        return ans[n][4];
    }
};