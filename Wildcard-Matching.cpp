1class Solution {
2    private:
3    int n,m;
4    int dp[2001][2001];
5public:
6    bool solve(string &s, string &p,int i,int j){
7         if(i<0&&j<0){
8            return true;
9         }
10
11         if(j<0){  //means i>=0
12             return false;
13         }
14
15         if(i<0){
16            while(j>=0&&p[j]=='*'){
17                j--;
18            }
19            return j<0;
20         }
21         
22         if(dp[i][j]!=-1)return dp[i][j];
23
24        if(s[i]==p[j]){
25            return  dp[i][j]=solve(s,p,i-1,j-1);
26        }
27
28        if(p[j]=='?'){
29            return  dp[i][j]=solve(s,p,i-1,j-1);
30        }
31
32
33        if(p[j]=='*'){
34            return dp[i][j]=solve(s,p,i-1,j)||solve(s,p,i,j-1);
35        }
36
37        return dp[i][j]=false;
38
39    }
40    bool isMatch(string s, string p) {
41        n=s.length();
42        m=p.length();
43        
44        memset(dp,-1,sizeof(dp));
45
46        return solve(s,p,n-1,m-1);
47    }
48};