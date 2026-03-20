1class Solution {
2public:
3//{ind,tight,leadingZeroes,last,isInc,isDec,digitSum}
4typedef long long ll;
5ll dp[20][2][2][11][2][2][150];
6bool isGood(int &num){
7    string x=to_string(num);
8    bool isInc=true;
9    bool isDec=true;
10    for(int i=1;i<x.length();i++){
11        if(x[i]<=x[i-1]){
12           isInc=false;
13           break;
14        }
15    }
16
17    for(int i=1;i<x.length();i++){
18        if(x[i]>=x[i-1]){
19           isDec=false;
20           break;
21        }
22    }
23    return (isInc||isDec);
24}
25
26
27ll solve(int ind,bool tight,int leadZero,int last,bool isInc,bool isDec,int digitSum,string &s){
28    if(ind==s.length()){
29        return (isInc||isDec||isGood(digitSum));
30    }
31
32    if(dp[ind][tight][leadZero][last][isInc][isDec][digitSum]!=-1)return dp[ind][tight][leadZero][last][isInc][isDec][digitSum];
33    ll ans=0;
34    int limit=tight?s[ind]-'0':9;
35    for(int i=0;i<=limit;i++){
36       bool newIsInc=isInc,newIsDec=isDec;
37       if(!leadZero){
38            if(last>=i){
39                newIsInc=false;
40            }
41            if(last<=i){
42                newIsDec=false;
43            }
44       }
45        ans+=solve(ind+1,tight &&(i==(s[ind]-'0')),leadZero &&(i==0),i, newIsInc,newIsDec,digitSum+i,s);
46    }
47    return dp[ind][tight][leadZero][last][isInc][isDec][digitSum]=ans;
48}
49
50    ll countFancy(ll l,ll r){
51       
52        string x=to_string(l-1);
53        memset(dp,-1,sizeof (dp));
54        ll val1=solve(0,1,1,10,1,1,0,x);//{ind,tight,leadigZeroes,last,isInc,isDec,digitSum,string}
55        string y=to_string(r);
56        memset(dp,-1,sizeof (dp));
57        ll val2=solve(0,1,1,10,1,1,0,y);
58        return val2-val1;
59    }
60};