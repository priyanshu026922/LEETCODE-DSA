class Solution {
public:
    bool hasSameDigits(string s) {
        int n=s.length();
        while(n>2){
        for(int i=0;i<n-1;i++){
            int x=((s[i]-'0')+(s[i+1]-'0'))%10;
            s[i]=x+'0';
        }
            n--;
        }
        int m=s.length();
        if(s[0]!=s[1])return false;
        return true;
    }
};