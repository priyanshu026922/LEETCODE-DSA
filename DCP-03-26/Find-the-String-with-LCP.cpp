1class Solution {
2public:
3    vector<vector<int>> check(string &word){
4        int n=word.length();
5        vector<vector<int>>dp(n,vector<int>(n,0));
6        for(int j=0;j<n;j++){
7           dp[n-1][j]=(word[n-1]==word[j]?1:0);
8        }
9
10        for(int i=0;i<n;i++){
11            dp[i][n-1]=(word[n-1]==word[i]?1:0);
12        }
13
14        for(int i=n-2;i>=0;i--){
15            for(int j=n-2;j>=0;j--){
16                if(word[i]!=word[j]){
17                    dp[i][j]=0;
18                }else{
19                    dp[i][j]=1+dp[i+1][j+1];
20                }
21            }
22        }
23        return dp;
24    }
25
26    string findTheString(vector<vector<int>>& lcp) {
27        int n=lcp.size();
28
29        string word(n,'$');
30        for(int i=0;i<n;i++){
31            for(int j=0;j<i;j++){
32                if(lcp[j][i]!=0){
33                    word[i]=word[j];
34                    break;
35                }
36            }
37
38            if(word[i]=='$'){
39
40                vector<bool>forbidden(26,false);
41                for(int j=0;j<i;j++){
42                   if(lcp[j][i]==0){
43                     forbidden[word[j]-'a']=true;
44                   }
45                }
46
47                for(int j=0;j<26;j++){
48                    if(forbidden[j]==false){
49                        word[i]=j+'a';
50                        break;
51                    }
52                }
53
54                if(word[i]=='$')return "";
55            }
56        }
57        return check(word)==lcp?word:"";
58    }
59};