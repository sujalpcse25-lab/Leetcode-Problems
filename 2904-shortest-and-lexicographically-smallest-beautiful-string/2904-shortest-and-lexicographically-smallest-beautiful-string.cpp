class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int ones = 0;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            if (s[right] == '1') {
                ones++;
            }

            while (ones > k || (left < right && s[left] == '0')) {
                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }

            if (ones == k) {
                string current = s.substr(left, right - left + 1);

                if (ans == "" ||
                    current.size() < ans.size() ||
                    (current.size() == ans.size() && current < ans)) {
                    ans = current;
                }
            }
        }

        return ans;
    }
};