1class Solution {
2public:
3typedef long long ll;
4    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
5       vector<ll>t;
6       ll count=0;
7       ll n=t1.size();
8       ll val=0;
9       for(ll i=0;i<n;i++){
10            if(t1[i]>=t2[i]){
11               val+=t1[i];
12               count++;
13            }else{
14               val+=t2[i];
15               t.push_back(t1[i]-t2[i]);
16            }
17       }
18       sort(begin(t),end(t));
19       reverse(begin(t),end(t));
20      ll p=0;
21       while(count<k){
22         count++;
23         val+=t[p];
24         p++;
25       }
26       return val;
27    }
28};