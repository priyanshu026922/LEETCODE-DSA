1class Solution {
2private:
3   int n;
4   int dp[2001];
5
6public:
7    void cal(string &s,vector<vector<int>>&pal){
8       for(int len=1;len<=n;len++){
9          for(int i=0;i<n+1-len;i++){
10            int j=len+i-1;
11
12            if(s[i]==s[j]){
13                if(len<=2){
14                    pal[i][j]=1;
15                }else{
16                    pal[i][j]=pal[i+1][j-1];
17                }
18            }
19          }
20       }
21    }
22    bool isPalindrome(int i,int j,vector<vector<int>>&pal){
23         return pal[i][j];
24    }
25
26    int solve(string &s,int i,vector<vector<int>>&pal){
27        
28        if(i==s.length()){
29            return 0;
30        }
31
32        if(dp[i]!=-1)return dp[i];
33
34
35        
36        int mini=n;
37        for(int j=i;j<n;j++){
38            if(isPalindrome(i,j,pal)){
39                mini=min(mini,1+solve(s,j+1,pal));
40            }
41        }
42
43       return  dp[i]=mini;  
44    }
45
46    int minCut(string s) {
47       
48        n=s.length();
49         memset(dp,-1,sizeof(dp));
50        
51         vector<vector<int>>pal(n+1,vector<int>(n+1,0));
52
53         cal(s,pal);
54        return solve(s,0,pal)-1;
55    }
56};