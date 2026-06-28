1class Solution {
2public:
3    int maximumLength(vector<int>& nums) {
4        int n=nums.size();
5        //arr of positive numbers
6        //we need to select a subset of nums
7
8        unordered_map<int,int>mp1;//to store the frequency
9        unordered_map<int,int>mp2;//to store the count of its subset
10        
11        for(auto it:nums){
12            mp1[it]++;
13            mp2[it]=1;
14            
15        }
16
17        vector<pair<int,int>>vec;
18
19
20        for(auto it:mp1){
21            vec.push_back({it.first,it.second});
22        }
23        
24        
25        int maxi=1;
26        sort(begin(vec),end(vec));
27        for(int i=0;i<vec.size();i++){
28            if(vec[i].first==1){
29                if(vec[i].second%2!=0){
30                    maxi=vec[i].second;
31                }else{
32                    maxi=max(1,vec[i].second-1);
33                }
34                
35                continue;
36            }
37
38
39            int val=vec[i].first;
40            int cnt=vec[i].second;
41
42            int x=sqrt(val);
43
44            if(x*x!=val)continue;
45
46            if(mp1.find(x)!=mp1.end()&&mp1[x]>=2){
47                mp2[val]=mp2[x]+2;
48            }
49        }
50
51        for(auto it:mp2){
52            maxi=max(maxi,it.second);
53        }
54        return maxi;
55
56
57
58       
59    }
60};