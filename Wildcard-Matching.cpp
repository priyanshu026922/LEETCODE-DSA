1class Solution {
2public:
3    bool isMatch(string s, string p) {
4       int  n=s.length();
5       int m=p.length();
6        
7
8        vector<int>prev(m+1,0);
9        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
10        prev[0]=1;
11              int k=1;
12              while(k<=m){
13                if(p[k-1]!='*')break;
14
15                prev[k]=1;
16                k++;
17              }
18
19
20              for(int i=1;i<=n;i++){
21                vector<int>curr(m+1,0);
22                for(int j=1;j<=m;j++){
23                     if(s[i-1]==p[j-1]){
24                         curr[j]=prev[j-1];
25                    }
26
27                    else if(p[j-1]=='?'){
28                        curr[j]=prev[j-1];
29                    }
30
31
32                    else if(p[j-1]=='*'){
33                        curr[j]=prev[j]||curr[j-1];
34                    }
35
36                    else curr[j]=false;
37             }
38
39             prev=curr;
40              }
41               return prev[m];
42    }
43};