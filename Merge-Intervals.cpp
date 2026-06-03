1class Solution {
2public:
3    vector<vector<int>> merge(vector<vector<int>>& intervals) {
4        int n=intervals.size();
5        sort(begin(intervals),end(intervals));
6        vector<vector<int>>ans;
7        vector<int>a;
8        for(int i=0;i<n;i++){
9            int x=intervals[i][0];
10            int y=intervals[i][1];
11            if(a.empty()){
12                a.push_back(x);
13                a.push_back(y);
14            }
15
16            else if(a.back()>=x){
17                int val=a.back();
18                a.pop_back();
19                int maxi=max(val,y);
20                a.push_back(maxi);
21            }
22
23            else if(!a.empty()&&x>a.back()){
24                 ans.push_back(a);
25                 a[0]=x;
26                 a[1]=y;
27            }
28        }
29        if(!a.empty()){
30            ans.push_back(a);
31        }
32        return ans;
33    }
34};