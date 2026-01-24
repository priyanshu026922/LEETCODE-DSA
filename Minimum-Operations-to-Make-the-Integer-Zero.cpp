1class Solution {
2public:
3    int makeTheIntegerZero(int num1, int num2) {
4       
5      long long  t=0;
6      while(t<=36){
7        long long val=1LL*num1-(1LL*t*num2);
8        if(val<0)return -1;
9        if(__builtin_popcountll(val)<=t&&t<=val){
10            return t;
11        } 
12        t++;
13      }
14      return -1;
15    }
16};