class Solution {
public:
    typedef long long ll;
    ll numOfSubsequences(string s) {
        int n=s.length();
      
        vector<ll>cnt_t(n+1,0);
        
        if(s[n-1]=='T')cnt_t[n-1]=1LL;
        for(int i=n-2;i>=0;i--){
            cnt_t[i]=cnt_t[i+1]+(s[i]=='T');
        }

        ll ans=0;
        ll l=0;
        ll maxi=0;
        ll m=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L')l++;
            else if(s[i]=='C'){
                ans+=(l*cnt_t[i]);
              
            }
              m=max(m,l*cnt_t[i]);
        }

        ll lc=0;
        ll q=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L')q++;
            else if(s[i]=='C')lc+=q;
        }
        

        ll ct=0;
        ll t=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='T')t++;
            else if(s[i]=='C')ct+=t;
        }

        // cout<<"lc:::"<<lc<<"ct:::"<<ct<<endl;
        ll val=max({lc,ct,m});
        

        return ans+val;
    }
};