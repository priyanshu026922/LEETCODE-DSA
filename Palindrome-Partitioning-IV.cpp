1class Solution {
2private:
3    int n;
4public:
5   bool isPalindrome(int i,int j,vector<vector<int>>&pal){
6       return pal[i][j];
7   }
8    bool solve(string &s,int i,int cnt,vector<vector<int>>&pal,  vector<vector<int>>&dp){
9        if(cnt>3)return 0;
10        
11        if(i==s.length()){
12            return (cnt==3);
13        }
14
15        if(dp[i][cnt]!=-1)return dp[i][cnt];
16
17        for(int j=i;j<n;j++){
18            if(isPalindrome(i,j,pal)){
19                if(solve(s,j+1,cnt+1,pal,dp)){
20                    return dp[i][cnt]=true;
21                }
22            }
23        }
24
25        return dp[i][cnt]=false;
26    }
27
28    bool checkPartitioning(string s) {
29        n=s.length();
30        vector<vector<int>>pal(n,vector<int>(n,0));
31          vector<vector<int>>dp(n,vector<int>(n,-1));
32        
33
34        for(int len=1;len<=n;len++){
35            for(int i=0;i<n+1-len;i++){
36                int j=len+i-1;
37
38                if(s[i]==s[j]){
39                    if(len<=2){
40                        pal[i][j]=1;
41                    }else{
42                        pal[i][j]=pal[i+1][j-1];
43                    }
44                }
45            }
46        }
47
48
49        return solve(s,0,0,pal,dp);
50    }
51};