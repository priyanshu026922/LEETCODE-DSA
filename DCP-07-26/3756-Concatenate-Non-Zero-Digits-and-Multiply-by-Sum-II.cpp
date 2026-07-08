class Solution {
public:
    int mod=1e9+7;
    typedef long long ll;
    ll power(ll x,ll y){

        ll res=1;
        while(y>0){
            if(y%2!=0){
                res=(res*x)%mod;
            }

            x=(x*x)%mod;

            y/=2;
        }

        return res;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.length(); 
        vector<ll>prefSum(n,0);
        vector<ll>cnt(n,0);
        vector<ll>num(n,0);
        
        ll val=0;
        for(int i=0;i<n;i++){
            ll x=s[i]-'0';

            if(x!=0){
                val=(val*10LL+x)%mod; 
            }

            prefSum[i]=x+(i>=1?prefSum[i-1]:0);
            cnt[i]=(x!=0?1:0)+(i>=1?cnt[i-1]:0);

            num[i]=val;
        }
    
        vector<int>ans;


        for(auto &it:queries){
            int i=it[0];
            int j=it[1];

            ll c=cnt[j]-(i>=1?cnt[i-1]:0);
            ll num2=num[j];
            ll num1=0;
            if(i>=1){
                num1=num[i-1];
            }

            ll pref=prefSum[j]-(i>=1?prefSum[i-1]:0);


            //ans would
            //num2-num1*10^(c)
            ll p=(1LL*num2-(1LL*num1*power(10,c)+mod)%mod+mod)%mod;

            ll q=(p*pref)%mod;
            ans.push_back(q);

        }

        return ans;
    }
};