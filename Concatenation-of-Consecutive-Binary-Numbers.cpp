1class Solution {
2public:
3    long long mod=1e9+7;
4    int concatenatedBinary(int n) {
5        long long x=0;
6        for(long long num=1;num<=n;num++){
7            int  t=32-__builtin_clz(num);
8            x=(x<<t);
9            // x=x%mod;
10            x=(x|num)%mod;
11            // x=x%mod;
12            // cout<<x<<endl;
13        }
14        return (int)x;
15    }
16}; 