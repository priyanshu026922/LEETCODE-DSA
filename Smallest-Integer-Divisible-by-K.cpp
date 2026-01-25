1class Solution {
2public:
3    int smallestRepunitDivByK(int k) {
4       long i=0;
5       long long rem=0;
6       while(i<k){
7           rem=(10*rem+1)%k;
8           if(rem==0)return i+1;
9           i++;
10       }
11       return -1;
12    }
13};