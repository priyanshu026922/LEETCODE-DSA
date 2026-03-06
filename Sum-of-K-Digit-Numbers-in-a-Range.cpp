1class Solution { 
2public:
3typedef long long ll;
4ll mod=1e9+7;
5ll power(ll a,ll b) {
6    ll result = 1;
7    while(b) {
8        if (b & 1) 
9        result = (result * a)%mod;
10        a = (a * a)%mod;
11        b >>= 1;
12    }
13    return result;
14}
15
16    int sumOfNumbers(int l, int r, int k) {
17        ll sum=0;
18        for(int i=l;i<=r;i++){
19            sum=(sum+i)%mod;
20        }
21
22        ll x=r-l+1;
23        ll y=k-1;
24        ll s=(power(x,y)*sum)%mod;
25        ll g=(power(10,k)-1+mod)%mod;
26        ll inv=power(9,mod-2);
27        ll ans=s;
28        ans=(ans*g)%mod;
29        ans=(ans*inv)%mod;
30        // ll ans=(s*(power(10,k)-1LL));
31        // ans=ans/9LL;
32        return ans;
33    }
34};