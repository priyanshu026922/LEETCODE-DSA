class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==dividend)return 1;

        int sign=true;
       if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        if(dividend>=0&&divisor<0){
            sign=false;
        }
         
        if(dividend<0&&divisor>=0){
            sign=false;
        }

        long long n=llabs(dividend);
        long long  m=llabs(divisor);

       long long ans=0;
        while(n>=m){
            int cnt=0;
            while(n>=(m<<(cnt+1))){
                cnt++;
            }

            ans+=(1<<cnt);
            n-=(m<<cnt);
        }
 

        if(ans>INT_MAX){
            return INT_MAX;
        }

        if(ans>INT_MAX&&sign){
            return INT_MAX;
        }
        
        if(ans>INT_MAX&&!sign){
            return INT_MIN;
        }
        return sign?ans:-ans;

    }
};