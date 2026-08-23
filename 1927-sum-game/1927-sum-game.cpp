class Solution {
public:
    bool sumGame(string num) {
        int n=num.size(), a=0, b=0, q1=0, q2=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?') q1++;
            else a+=num[i]-'0';
            if(num[n/2+i]=='?') q2++;
            else b+=num[n/2+i]-'0';
        }
        if((q1+q2)%2) return true;
        return a-b != 9*(q2-q1)/2;
    }
};