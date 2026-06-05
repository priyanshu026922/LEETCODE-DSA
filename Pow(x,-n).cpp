1class Solution {
2public:
3   double cal(double x,long long n){
4    double res=1.0;
5    while(n>0){
6        if(n%2==1){
7            res*=x;
8        }
9        x*=x;
10        n/=2;
11    }
12    return res;
13   }
14
15    double myPow(double x, int n) {
16        long long N=n;
17        if(N<0){
18            return cal((double)1.0/x,-1*N);
19        }
20        return cal(x,N);
21    }
22};