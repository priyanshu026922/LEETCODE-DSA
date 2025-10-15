class Solution {
public:
// int solve(int ind1,int ind2,string text1, string text2){
//     if(ind1<0||ind2<0){
//         return 0;
//     }
//     int m=-1e9,nm=-1e9;
//    if(text1[ind1]==text2[ind2])  m=1+solve(ind1-1,ind2-1,text1,text2);
//   else   nm=max(solve(ind1-1,ind2,text1,text2),solve(ind1,ind2-1,text1,text2));
//     return max(m,nm);
// }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=0;i<=n1;i++){
            dp[i][0]=0;
        }
         for(int i=0;i<=n2;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                int m=-1e9,nm=-1e9;
                if(text1[i-1]==text2[j-1])   dp[i][j]=1+dp[i-1][j-1];
                else  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           
            }
        }




        return dp[n1][n2];
    }
};