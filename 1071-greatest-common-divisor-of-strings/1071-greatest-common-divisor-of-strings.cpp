class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Function to check if str1 can be constructed by repeating str2
        auto canConstruct = [](const string& str, const string& pattern) {
            int lenStr = str.length(), lenPattern = pattern.length();
            if (lenStr % lenPattern != 0) return false; // str can't be formed by pattern
            string repeatedPattern = "";
            for (int i = 0; i < lenStr / lenPattern; ++i) {
                repeatedPattern += pattern;
            }
            return repeatedPattern == str;
        };

        // The GCD string must be a prefix of both str1 and str2
        string gcdCandidate = str1.substr(0, __gcd(str1.length(), str2.length()));
        
        // Check if the candidate can construct both strings
        if (canConstruct(str1, gcdCandidate) && canConstruct(str2, gcdCandidate)) {
            return gcdCandidate;
        }
        return ""; // Return empty string if no GCD exists
    }
};
