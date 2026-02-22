1class Solution {
2public:
3    int binaryGap(int n) {
4        int maxi=0;
5        bool b=false;
6        int prev=-1;
7        for(int i=0;i<32;i++){
8            if(n&(1<<i)){
9                if(b){
10                    maxi=max(maxi,i-prev);
11                }else{
12                    b=true;
13                }
14                prev=i;
15            }
16        }
17        return maxi;
18    }
19};