1class Solution {
2public:
3    typedef long long ll;
4    ll minMoves(vector<int>& balance) {
5        ll n=balance.size();
6        ll c=0;
7        ll ind=-1;
8        for(int i=0;i<n;i++){
9            if(balance[i]<0){
10                c++;
11                ind=i;
12            }
13        }
14        
15        if(c==0)return 0;
16        ll sum=accumulate(begin(balance),end(balance),0LL);
17        if(sum<0)return -1;
18       
19       vector<int>dis(n,0);
20       for(int i=0;i<n;i++){
21        if(i==ind)continue;
22        dis[min(abs(i-ind),abs(n -abs(i-ind)))]+=balance[i];
23       }
24       ll tar=-balance[ind];
25       ll i=1;
26       ll cost=0;
27       while(tar>0&&i<n){
28        if(dis[i]>=tar){
29            cost+=1LL*(tar*i);
30            tar=0;
31            break;
32        }
33        cost+=(dis[i])*i;
34        tar-=dis[i];
35        i++;
36       }
37       return cost;
38    }
39};