1class Solution {
2public:
3    typedef long long ll;
4    ll findLIS(vector<ll>&v,int m){
5        vector<ll>temp;
6        temp.push_back(v[0]);
7        int len=1;
8        for(int i=1;i<m;i++){
9            if(v[i]>temp.back()){
10                temp.push_back(v[i]);
11                len++;
12            }else{
13                int ind=lower_bound(begin(temp),end(temp),v[i])-begin(temp);
14                temp[ind]=v[i];
15            }
16        }
17        return len;
18    }
19
20    int longestSubsequence(vector<int>& nums) {
21        int n=nums.size();
22        vector<vector<ll>>vec(32);
23        ll maxi=0;
24        for(int i=0;i<n;i++){
25             int  val=nums[i];
26            for(int j=0;j<32;j++){
27                if(val&(1<< j)){
28                    vec[j].push_back(val);
29                }
30            }
31        }
32        
33        for(int i=0;i<32;i++){
34            if(vec[i].empty())continue;
35            vector<ll>v=vec[i];
36            int m=v.size();
37            maxi=max(maxi,findLIS(v,m));
38        }
39        return maxi; 
40    }
41};