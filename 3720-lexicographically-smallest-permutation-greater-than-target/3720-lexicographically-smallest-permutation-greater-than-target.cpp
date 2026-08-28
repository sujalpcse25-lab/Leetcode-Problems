class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {0};

        for (char c : s) {
            cnt[c - 'a']++;
        }

        for (int i = s.size() - 1; i >= 0; i--) {

            int temp[26];

            for (int j = 0; j < 26; j++) {
                temp[j] = cnt[j];
            }

            // Use target's prefix
            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (temp[x] == 0) {
                    possible = false;
                    break;
                }

                temp[x]--;
            }

            if (!possible) {
                continue;
            }

            // Find smallest character greater than target[i]
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (temp[c] == 0) {
                    continue;
                }

                string ans = "";

                // Keep prefix same as target
                for (int j = 0; j < i; j++) {
                    ans += target[j];
                }

                // Make the permutation greater
                ans += char('a' + c);
                temp[c]--;

                // Put remaining characters in smallest order
                for (int j = 0; j < 26; j++) {
                    while (temp[j] > 0) {
                        ans += char('a' + j);
                        temp[j]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }
};