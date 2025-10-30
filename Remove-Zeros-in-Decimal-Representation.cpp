class Solution {
public:
    long long removeZeros(long long n) {
        string x=to_string(n);
        string t="";
       for(char ch:x){
         if(ch!='0')  t+=ch;
       }
        if(t.empty())return 0;
        return stoll(t);
    }
};