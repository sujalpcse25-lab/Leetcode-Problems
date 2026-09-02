class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int freq[26] = {0};

        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";

        for (int i = 0; i < target.size(); i++) {

            int x = target[i] - 'a';

            // Try to keep target[i]
            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
                continue;
            }

            // Cannot keep target[i].
            // Try the smallest character greater than target[i].
            for (int j = x + 1; j < 26; j++) {
                if (freq[j] > 0) {
                    ans += char('a' + j);
                    freq[j]--;

                    // Fill remaining positions with smallest characters
                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            ans += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return ans;
                }
            }

            // Need to backtrack
            for (int k = i - 1; k >= 0; k--) {
                freq[ans[k] - 'a']++;

                int cur = target[k] - 'a';

                for (int j = cur + 1; j < 26; j++) {
                    if (freq[j] > 0) {
                        ans[k] = char('a' + j);
                        freq[j]--;

                        ans.resize(k + 1);

                        for (int p = 0; p < 26; p++) {
                            while (freq[p] > 0) {
                                ans += char('a' + p);
                                freq[p]--;
                            }
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

        // s can form exactly target.
        // We need to make an earlier position larger.
        for (int k = target.size() - 1; k >= 0; k--) {
            freq[ans[k] - 'a']++;

            int cur = target[k] - 'a';

            for (int j = cur + 1; j < 26; j++) {
                if (freq[j] > 0) {
                    ans[k] = char('a' + j);
                    freq[j]--;

                    ans.resize(k + 1);

                    for (int p = 0; p < 26; p++) {
                        while (freq[p] > 0) {
                            ans += char('a' + p);
                            freq[p]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};