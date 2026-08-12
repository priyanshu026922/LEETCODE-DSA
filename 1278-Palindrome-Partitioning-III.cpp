class Solution {
private:
    int n;
public:
    int dp[101][101];
    int solve(string &s,int k,vector<vector<int>>&pal,int i){
       
        if(i==n){
            if(k==0)return 0;
            return INT_MAX;
        }

        if(k<=0)return INT_MAX;

        if(dp[i][k]!=-1)return dp[i][k];

        int mini=INT_MAX;
        
        for(int j=i;j<n;j++){
            int val=pal[i][j];
            int x=solve(s,k-1,pal,j+1);
            if(x!=INT_MAX){
                   mini=min(mini,val+x);
            }
        }
        // cout<<"i::"<<i<<":::"<<mini<<endl;
        return dp[i][k]=mini;
    }  

    int palindromePartition(string s, int k) {
        n=s.length();
        vector<vector<int>>p(n+1,vector<int>(n+1,0));
         for(int len=1;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                    int j=i+len-1;
                    if(s[i]!=s[j]){
                        if(len<=2){
                            p[i][j]=1;
                        }else{
                            p[i][j]=p[i+1][j-1]+1;
                        }
                        
                    }else{
                        if(len<=2){
                            p[i][j]=0;
                        }else{
                            p[i][j]=p[i+1][j-1];
                        }
                    }
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<p[i][j]<<" ";
            }

            cout<<endl;
        }
        
        memset(dp,-1,sizeof(dp));

        return solve(s,k,p,0);
    }
};