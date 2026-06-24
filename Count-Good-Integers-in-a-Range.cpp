1class Solution {
2public:
3    typedef long long ll;
4    ll dp[20][3][2][12][2];
5    ll solve(string s,int j,bool tight,bool isLeadingZero,int k,int last,bool pos){
6        if(j==s.length()){
7            return pos;
8        }
9        
10        if(dp[j][tight][isLeadingZero][last][pos]!=-1)return dp[j][tight][isLeadingZero][last][pos];
11
12        int limit=tight?(s[j]-'0'):9;
13        ll cnt=0;
14        for(int i=0;i<=limit;i++){
15            bool t=pos;
16            bool l=isLeadingZero&&(i==0);
17            if(l){
18                 cnt+=solve(s,j+1,tight &&(i==(s[j]-'0')),l,k,10,t);
19            }else{
20                //leading Zero===false:::
21
22                // if(last!=10&&abs(i-last)<=k){
23                //     //    bool p=t;
24                //     //    t=t&&p;
25                // }else{
26                //     t=false;
27                // }
28
29                if(last==10){
30                    t=true;
31                }else if(abs(i-last)<=k){
32                    t=pos;
33                }else {
34                    t=false;
35                }
36                  
37                            
38                cnt+=solve(s,j+1,tight &&(i==(s[j]-'0')),l,k,i,t);
39            } 
40        }
41        return dp[j][tight][isLeadingZero][last][pos]=cnt;
42    }
43
44    ll goodIntegers(ll l, ll r, int k) {
45
46        string x=to_string(l-1);
47        memset(dp,-1,sizeof(dp));
48
49        ll ans1=solve(x,0,1,1,k,10,0);//{string,tight,isLeadingZero,k,last}
50
51         string y=to_string(r);
52        memset(dp,-1,sizeof(dp));
53
54        ll ans2=solve(y,0,1,1,k,10,0);
55        return ans2-ans1;
56        
57    }
58};