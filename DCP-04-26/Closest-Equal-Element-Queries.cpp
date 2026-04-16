1class Solution {
2public:
3    vector<int> solveQueries(vector<int>& nums, vector<int>& queries){
4        unordered_map<int,vector<int>>mp;
5        int n=nums.size();
6        for(int i=0;i<nums.size();i++){
7            mp[nums[i]].push_back(i);
8        }
9        
10        vector<int>ans;
11        for(auto q:queries){
12            int ind=q;
13            int val=nums[ind];
14
15            if(mp[val].size()<2){
16                ans.push_back(-1);
17                continue;
18            }
19            
20            auto &v=mp[val];
21            auto it=lower_bound(v.begin(),v.end(),ind);
22            int i1=it-begin(v);
23            
24            int val1=v[i1];
25
26            int i2=i1+1;
27            if(i2==v.size()){
28                i2=0;
29            }
30            
31            int val2=v[i2];
32           
33            int i3=i1-1;
34            if(i3<0){
35                i3=v.size()-1;;
36            }
37            
38            int val3=v[i3];
39            int x=min(abs(val1-val3),n-abs(val1-val3));
40            int y=min(abs(val1-val2),n-abs(val1-val2));
41            ans.push_back(min(x,y));
42
43        }
44        return ans;
45    }
46};