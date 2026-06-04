1class Solution {
2public:
3    bool static cmp(vector<int>&v1,vector<int>&v2){
4        if(v1[1]==v2[1]){
5            return v1[0]<v2[0];
6        }
7
8        return v1[1]<v2[1];
9    }
10    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
11        
12        int n=intervals.size();
13        sort(intervals.begin(),intervals.end(),cmp);
14        int prev=intervals[0][1];
15        int cnt=1;
16        for(int i=1;i<n;i++){
17           if(intervals[i][0]>=prev){
18            cnt++;
19            prev=intervals[i][1];
20           }
21        }
22        return n-cnt;
23    }
24};