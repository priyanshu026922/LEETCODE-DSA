1class Solution {
2public:
3    int minFlips(string s) {
4        int n=s.length();
5        int i=0;
6        int j=0;
7        int mini=INT_MAX;
8        int flip1=0;
9        while(j<2*n){
10            char exp_ch=(j%2==0)?'0':'1';
11            if(s[j%n]!=exp_ch){
12                flip1++;
13            }
14
15            if(j-i+1>n){
16                exp_ch=(i%2==0)?'0':'1';
17                if(s[i%n]!=exp_ch){
18                    flip1--;
19                }
20                i++;
21            }
22
23          if(j-i+1==n) mini=min({mini,flip1,n-flip1});
24            j++;
25        }
26        return mini;
27    }
28};