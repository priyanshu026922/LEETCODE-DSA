1class Solution {
2public:
3    int getReverse(int n){
4        int num=0;
5        while(n>0){
6           num=num*10+n%10;
7
8            n/=10;
9        }
10        return num;
11    }
12    int mirrorDistance(int n) {
13        int m=getReverse(n);
14        return abs(m-n);
15    }
16};