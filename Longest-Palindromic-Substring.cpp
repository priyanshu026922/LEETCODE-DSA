class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
       if(n<=1){
        return s;
       }
       string lps="";

       for(int i=0;i<n;i++){
        int l=i;
        int h=i;
        while(l>=0&&h<n&&s[l]==s[h]){
            l--;
            h++;
           
        }
          string p1 = s.substr(l + 1, h - l - 1);
        if(p1.length()>lps.length()){
            lps=p1;
        }
        l=i;
        h=i+1;
         while(l>=0&&h<n&&s[l]==s[h]){
            l--;
            h++;
           
        }
         p1 = s.substr(l + 1, h - l - 1);
        if(p1.length()>lps.length()){
            lps=p1;
        }
       }
       return lps;
    }
};