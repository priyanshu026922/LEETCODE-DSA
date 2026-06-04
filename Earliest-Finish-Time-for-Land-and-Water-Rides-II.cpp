1class Solution {
2public:
3     typedef pair<int,int> p;
4     bool static cmp(pair<int,int>&p1,pair<int,int>&p2){
5        int x=p1.first+p1.second;
6        int y=p2.first+p2.second;
7        return x<y;
8     }
9
10     int earliestFinishTime(vector<int>& ls,vector<int>& ld, vector<int>& ws, vector<int>& wd) {
11
12        int n=ls.size();
13        int m=ws.size();
14
15        vector<p>v1,v2;
16        for(int i=0;i<n;i++){ 
17            v1.push_back({ls[i],ld[i]});
18        }
19        
20        for(int i=0;i<m;i++){
21            v2.push_back({ws[i],wd[i]});
22        }
23        sort(begin(v1),end(v1),cmp);
24        sort(begin(v2),end(v2),cmp);
25
26        int mini=INT_MAX;
27        int val1=v1[0].first+v1[0].second;
28        for(int i=0;i<m;i++){
29            mini=min(mini,max(val1,v2[i].first)+v2[i].second);
30        }
31        
32        val1=v2[0].first+v2[0].second;
33        for(int i=0;i<n;i++){
34            mini=min(mini,max(val1,v1[i].first)+v1[i].second);
35        }
36
37        return mini;
38
39
40    }
41};