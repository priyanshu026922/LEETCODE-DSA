1class Solution {
2public:
3    int numSteps(string s) {
4        int n=s.length();
5        int op=0;
6        int carry=0;
7        for(int i=n-1;i>=1;i--){
8            if(((s[i]-'0')+carry)%2==1){
9                op+=2;
10                carry=1;
11            }else{
12                op++;
13            }
14        }
15        return op+carry;
16    }
17};