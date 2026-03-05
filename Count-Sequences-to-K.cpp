1class Solution {
2public:
3    int n;
4    typedef long long ll;
5    map<pair<int,double>,int>dp;
6    ll solve(vector<int>&nums,int ind,double k,double val){
7        if(ind==n){
8            if(abs(val-k)<1e-6)return 1;
9            return 0;
10        }
11        // if(dp[ind][val]!=-1.0)return dp[ind][val];
12        if(dp.find({ind,val})!=dp.end()){
13            return dp[{ind,val}];
14        }
15        ll nt=0,t1=0,t2=0;
16        nt=solve(nums,ind+1,k,val);
17        t1=solve(nums,ind+1,k,(val/(1.0*1LL*nums[ind])));
18        t2=solve(nums,ind+1,k,1.0*1LL*val*nums[ind]);
19        return dp[{ind,val}]=nt+t1+t2;
20    }
21    
22    int countSequences(vector<int>& nums,ll k) {
23           n=nums.size();
24        //    vector<vector<double>>dp(n+1,vector<double>(160,-1));
25           double x=double(k);
26           return solve(nums,0,x,1.0);
27    }
28};