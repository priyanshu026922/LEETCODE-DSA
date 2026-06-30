1class Solution {
2public:
3    int minCost(vector<int>& sP, vector<int>& hP, vector<int>& rC, vector<int>& cC) {
4        int val=0;
5        int miniX=min(sP[0],hP[0]);
6        int maxiX=max(sP[0],hP[0]);
7        for(int i=miniX;i<=maxiX;i++){
8            val+=rC[i];
9        }
10        
11        val-=rC[sP[0]];
12        int miniY=min(sP[1],hP[1]);
13        int maxiY=max(sP[1],hP[1]);
14
15        for(int i=miniY;i<=maxiY;i++){
16            val+=cC[i];
17        }
18        
19        val-=cC[sP[1]];
20        return val;
21
22    }
23};