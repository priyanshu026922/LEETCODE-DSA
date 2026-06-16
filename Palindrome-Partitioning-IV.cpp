1class Solution {
2private:
3    int n;
4public:
5    void cal(string &s,vector<vector<int>>&pal){
6
7        for(int len=1;len<=n;len++){
8                for(int i=0;i<n+1-len;i++){
9                    int j=len+i-1;
10
11                    if(s[i]==s[j]){
12                        if(len<=2){
13                            pal[i][j]=1;
14                        }else{
15                            pal[i][j]=pal[i+1][j-1];
16                        }
17                    }
18                }
19            }
20    }
21
22
23//    bool isPalindrome(int i,int j,vector<vector<int>>&pal){
24//        return pal[i][j];
25//    }
26
27    // bool solve(string &s,int i,int cnt,vector<vector<int>>&pal,  vector<vector<int>>&dp){
28    //     if(i==s.length()){
29    //         return (cnt==3);
30    //     }
31
32    //     if(dp[i][cnt]!=-1)return dp[i][cnt];
33
34    //     for(int j=i;j<n;j++){
35    //         if(isPalindrome(i,j,pal)){
36    //             if(solve(s,j+1,cnt+1,pal,dp)){
37    //                 return dp[i][cnt]=true;
38    //             }
39    //         }
40    //     }
41
42    //     return dp[i][cnt]=false;
43    // }
44
45    bool checkPartitioning(string s) {
46        n=s.length();
47        vector<vector<int>>p(n,vector<int>(n,0));
48        cal(s,p);
49       
50
51       for(int i=0;i<n;i++){
52         for(int j=n-1;j>i+1;j--){
53
54            if(p[0][i]&&p[j][n-1]&&p[i+1][j-1]){
55                return true;
56            }
57         }
58       }
59
60
61        return false;
62    }
63};