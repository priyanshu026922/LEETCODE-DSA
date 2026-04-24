1class Solution {
2public:
3    int furthestDistanceFromOrigin(string moves) {
4        int cnt=0;
5        int cntL=0;
6        int cntR=0;
7        for(char ch:moves){
8            if(ch=='L')cntL++;
9            else if(ch=='R')cntR++;
10            else cnt++;
11        }
12
13        if(cntL>cntR){
14            return cntL+cnt-cntR;
15        }
16        else if(cntR>cntL){
17            return cntR+cnt-cntL;
18        }
19        return cnt;
20    }
21};