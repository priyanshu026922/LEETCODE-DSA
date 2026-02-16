1class Solution {
2public:
3    int reverseBits(int n) {
4        vector<int>bits(32,0);
5        for(int i=0;i<32;i++){
6            if((n&(1<<i))){
7                  bits[i]=1;
8            }
9        }
10        long long ans=0;
11        for(int i=31;i>=0;i--){
12            if(bits[i]==1){
13                ans+=(1<<(31-i));
14            }
15        }
16        return (int)ans;
17    }
18};