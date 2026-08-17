class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mxlen = 0;
        for(int i = 0; i < s.length(); i++){
            bool visited[256] = {false};
            int len = 0;
            for(int j = i; j < s.length(); j++){
                if(visited[s[j]]){
                    break;
                }
                visited[s[j]] = true;
                len++;
                if(len > mxlen){
                    mxlen = len;
                }
            }
        }
        return mxlen;
    }
};