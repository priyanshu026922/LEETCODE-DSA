1class Solution {
2public:
3    int maxBuilding(int m, vector<vector<int>>& restrictions) {
4        //n-->no of buildings
5        //restrictions--->[id,maxH]====represnt building with id can have maxH that much
6        
7        //agar jispr restrictions na ho
8        //usko pehle hi max set krde 
9        ///[hr aage ka process start kre
10        restrictions.push_back({1,0});
11        restrictions.push_back({m,m-1});
12
13        sort(begin(restrictions),end(restrictions));
14        int n=restrictions.size();
15        int maxi=0;
16
17        for(int i=1;i<n;i++){
18            int diff=restrictions[i][0]-restrictions[i-1][0];
19            restrictions[i][1]=min(restrictions[i][1],restrictions[i-1][1]+diff);
20        }
21
22        for(int i=n-2;i>=0;i--){
23            int diff=restrictions[i+1][0]-restrictions[i][0];
24            restrictions[i][1]=min(restrictions[i][1],restrictions[i+1][1]+diff);
25        }
26
27        for(int i=1;i<n;i++){
28             int id1=restrictions[i-1][0];
29             int id2=restrictions[i][0];
30
31
32             int h1=restrictions[i-1][1];
33             int h2=restrictions[i][1];
34
35
36             int val=max(h1,h2)+(id2-id1-abs(h2-h1))/2;
37
38             maxi=max(maxi,val);
39        }
40
41        return maxi;
42
43    }
44};