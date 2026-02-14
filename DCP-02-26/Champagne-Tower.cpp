1class Solution {
2public:
3double dp[101][101];
4    double solve(int poured,int i,int j){
5        if(i<0||j<0||j>i)return 0.0;
6        if(i==0&&j==0)return poured;//we reached top
7        
8        if(dp[i][j]!=-1){
9            return dp[i][j];
10        }
11        double l=(solve(poured,i-1,j-1)-1)/2.0;
12        double r=(solve(poured,i-1,j)-1)/2.0;
13        
14        if(l<0){
15            l=0.0;
16        }
17        if(r<0){
18            r=0.0;
19        }
20        return dp[i][j]=l+r;
21
22    }
23    double champagneTower(int poured, int query_row, int query_glass) {
24        for(int i=0;i<101;i++){
25            for(int j=0;j<101;j++){
26                dp[i][j]=-1;
27            }
28        }
29         return min(1.0,solve(poured,query_row,query_glass));
30    }
31};