1class Solution {
2public:
3    bool isOneBitCharacter(vector<int>& bits) {
4        int n=bits.size();
5        int i;
6        bool b=false;
7        for( i=0;i<n;){
8             int  ch1=bits[i];
9             if(i==n-1){
10                b=true;
11                
12             }
13           
14            if(ch1==0)i++;
15            else{
16                i+=2;
17            }
18
19           
20        }
21
22       return b ;
23    }
24};