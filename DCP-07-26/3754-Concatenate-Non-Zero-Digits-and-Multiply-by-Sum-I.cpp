class Solution {
public:
    typedef long long ll;
    ll sumAndMultiply(int n) {
        ll sum=0;
        ll num=0;
        int x=1;
        while(n>0){
            int val=n%10;

            if(val!=0){
                num=x*val+num;
                sum+=val;
                x*=10;
            }

            n/=10;

        }

        return num*sum;
    }
};