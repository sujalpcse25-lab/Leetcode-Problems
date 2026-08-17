class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        string prefix = strs[0];
        for(int i = 1; i < strs.size(); i++){
            //shorten the prefix until it matches the start of strs[i]
            while(strs[i].substr(0, prefix.length()) != prefix){
                prefix.pop_back();//Remove last character
                if(prefix.empty()){
                    return "";
                }
            }
        }
        return prefix;
    }
};