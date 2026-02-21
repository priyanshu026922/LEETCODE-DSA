1class Solution {
2public:
3    bool isPrime(int x){
4        if(x<=1)return false;
5        for(int i=2;i*i<=x;i++){
6            if(x%i==0)return false;
7        }
8        return true;
9    }
10    int countPrimeSetBits(int left, int right) {
11        int cnt=0;
12        for(int i=left;i<=right;i++){
13            int x=__builtin_popcount(i);
14            if(isPrime(x)){
15                cnt++;
16            }
17        }
18         return cnt;
19    }
20};