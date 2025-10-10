class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        long res=0;
        int i=0;
        int sign=1;
        while(i<n&&s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            sign=-1;
            i++;
        }else if(s[i]=='+'){
              sign=1;
              i++;
        }
        while(i<n&&0<=s[i]-'0'&&s[i]-'0'<=9){
            res=res*10+(s[i]-'0');
            if(res*sign<=INT_MIN)return INT_MIN;
            if(res*sign>=INT_MAX)return INT_MAX;
            i++;
        }
        return (int)sign*res;
    }
};