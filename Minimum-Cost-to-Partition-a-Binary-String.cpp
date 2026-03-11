1class Solution {
2public:
3    typedef long long ll;
4    ll getVal(string &s,int l,int r,int encCost,int flatCost){
5        int cnt=0;
6        for(int i=l;i<=r;i++){
7            cnt+=(s[i]=='1'?1:0);
8        }
9
10        if(cnt==0){
11          return 1LL*flatCost;
12        }
13        return 1LL*(r-l+1)*cnt*encCost;
14    }
15
16    ll solve(int l,int r,string &s,int encCost,int flatCost){
17        
18         if(l>r){
19            return LLONG_MAX/2;
20        }
21        
22        if(l==r){
23            return (s[l]=='1')?encCost:flatCost;
24        }
25        
26        int mid=l+(r-l)/2;
27        ll val=getVal(s,l,r,encCost,flatCost);
28
29        if((r-l+1)%2==0){
30            val=min(val,solve(l,mid,s,encCost,flatCost)+solve(mid+1,r,s,encCost,flatCost));
31        }
32        return val;
33    }
34
35    ll minCost(string s, int encCost, int flatCost) {
36        int n=s.length();
37
38        if(n%2!=0){
39            return getVal(s,0,n-1,encCost,flatCost);
40        }
41        
42        ll val=getVal(s,0,n-1,encCost,flatCost);;
43        val=min(val,solve(0,n-1,s,encCost,flatCost));
44        return val;
45    }
46};