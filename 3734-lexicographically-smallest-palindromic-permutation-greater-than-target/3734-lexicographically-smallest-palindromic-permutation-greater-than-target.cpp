class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        string calendrix = s;

        int n = s.size();
        int halfLen = n / 2;

        int cnt[26] = {0};

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check if palindrome is possible
        int odd = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1) {
            return "";
        }

        int halfCnt[26];

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        string prefix = "";

        // Check whether the current prefix can still
        // produce a palindrome greater than target.
        auto possible = [&]() {
            int temp[26];

            for (int i = 0; i < 26; i++) {
                temp[i] = halfCnt[i];
            }

            string left = prefix;

            // Make the largest possible remaining half
            for (int i = 25; i >= 0; i--) {
                while (temp[i] > 0) {
                    left += char('a' + i);
                    temp[i]--;
                }
            }

            string candidate = left;

            if (odd == 1) {
                candidate += middle;
            }

            for (int i = left.size() - 1; i >= 0; i--) {
                candidate += left[i];
            }

            return candidate > target;
        };

        // Build the answer from left to right.
        for (int pos = 0; pos < halfLen; pos++) {

            bool found = false;

            // Always try the smallest character first.
            for (int c = 0; c < 26; c++) {

                if (halfCnt[c] == 0) {
                    continue;
                }

                halfCnt[c]--;
                prefix += char('a' + c);

                if (possible()) {
                    found = true;
                    break;
                }

                // Undo the choice
                prefix.pop_back();
                halfCnt[c]++;
            }

            if (!found) {
                return "";
            }
        }

        // Construct final palindrome
        string answer = prefix;

        if (odd == 1) {
            answer += middle;
        }

        for (int i = prefix.size() - 1; i >= 0; i--) {
            answer += prefix[i];
        }

        if (answer > target) {
            return answer;
        }

        return "";
    }
};