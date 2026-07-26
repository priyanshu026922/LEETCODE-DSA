class Solution {
public:
    typedef long long ll;
    int mod=1e9+7;
    static const int N=500001;
    ll fact[N];
    ll power(ll a,ll b){
        ll res=1;
        while(b>0){
            if(b&1){
                res=(res*a)%mod;
            }

            a=(a*a)%mod;
            b/=2;
        }
        return res;
    }

    void init(){
        fact[0]=1LL;
        for(int i=1;i<N;i++){
            fact[i]=(fact[i-1]*i)%mod;
        }
    }

    ll solve(ll n,ll r){
      if(r>n||r<0)return 0;

      ll a=fact[n];
      ll b=(fact[r]*fact[n-r])%mod;

      return (a*power(b,mod-2))%mod;
    }
    
    int countValidSequences(int m, int l) {
        init();
        ll n=m;
        ll k=l;
        ll x=solve(n-1,k-1);
        ll y=((n-k)%2==0?solve((n+k-2)/2,k-1):0);
        // cout<<x<<" "<<y<<endl;
        return (int)(x-y+mod)%mod;
    }
};