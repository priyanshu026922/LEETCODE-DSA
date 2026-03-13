1class Solution {
2public:
3typedef long long ll;
4    ll check(ll mid,int mountainH, vector<int>& workerT){
5        int n=workerT.size();
6        ll sum=0;
7        for(int i=0;i<n;i++){
8            ll val=sqrt(((2.0*mid)/workerT[i])+0.25)-0.5;
9            if(val>mid){
10                return false;
11            }
12            sum+=val;
13            if(sum>=mountainH){
14                return true;
15            }
16        }
17        return false;
18    }
19
20    ll minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes){
21       
22        ll l=1;
23        ll val=*max_element(begin(workerTimes),end(workerTimes));
24        ll r=val*( 1LL*mountainHeight*( 1LL*mountainHeight+1LL))/2LL;
25        ll ans=-1;
26
27        while(l<=r){
28            ll mid=l+(r-l)/2;
29            if(check(mid,mountainHeight,workerTimes)){
30                  ans=mid;
31                  r=mid-1;
32            }else{
33                l=mid+1;
34            }
35        }
36        return ans;
37    }
38};