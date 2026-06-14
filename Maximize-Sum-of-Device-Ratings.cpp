1class Solution {
2public:
3typedef long long ll;
4    ll maxRatings(vector<vector<int>>& units) {
5        //sare ko sort krdo
6        int n=units.size();
7        int m=units[0].size();
8        for(int i=0;i<n;i++){
9            sort(begin(units[i]),end(units[i]));
10        }
11
12        //sort krne ke baad saare array order mai aaeja
13
14        //maanlo ki:
15        //[1,9,10,11]
16        //[3,7,11,13]
17        //[8,9,10,12]
18        //[6,7,8,9]
19
20        ll sum=0;
21        ll mini=LLONG_MAX;
22        for(int i=0;i<n;i++){
23            sum=(sum+1LL*units[i][0]);
24            mini=min(mini,1LL*units[i][0]);
25        }
26
27        if(m==1){
28            return sum;
29        }
30         
31        ll sum1=0;
32        for(int i=0;i<n;i++){
33            sum1=(sum1+1LL*units[i][1]);
34        }
35        
36        ll maxi=LLONG_MIN;
37        for(int i=0;i<n;i++){
38            maxi=max(maxi,sum1+mini-1LL*units[i][1]);
39        }
40        return maxi;
41    }
42};