class Solution {
public:
    bool doesAliceWin(string s) {
        int n=s.length();
        int vow=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                vow++;
            }
        }
        if(vow%2){
            return true;
        }
        if(vow==0)return false;

       return true;
    }
};