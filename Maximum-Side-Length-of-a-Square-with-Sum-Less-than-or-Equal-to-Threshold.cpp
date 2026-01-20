1class Solution {
2public:
3int sumVal(int i,int j,int r2,int c2,  vector<vector<int>>&pref){
4   
5    int sum=pref[r2][c2];
6    if(i>0){
7        sum-=pref[i-1][c2];
8    }
9    if(j>0){
10        sum-=pref[r2][j-1];
11    }
12    if(i>0&&j>0){
13        sum+=pref[i-1][j-1];
14    }
15    return sum;
16}
17    int maxSideLength(vector<vector<int>>& mat, int threshold) {
18        int r=mat.size();
19        int c=mat[0].size();
20
21        vector<vector<int>>pref(r,vector<int>(c,0));
22        for(int i=0;i<r;i++){
23            for(int j=0;j<c;j++){
24                pref[i][j]=(i>0?pref[i-1][j]:0)+(j>0?pref[i][j-1]:0)-((i>0&&j>0)?pref[i-1][j-1]:0)+mat[i][j];
25
26            }
27        }
28        int best=0;
29        for(int i=0;i<r;i++){
30            for(int j=0;j<c;j++){
31
32               for(int k=0;k<min(r-i,c-j);k++){
33                   int r2=i+k;
34                   int c2=j+k;
35                   int val=sumVal(i,j,r2,c2,pref);
36                   if(val<=threshold){
37                       best=max(best,k+1);
38                   }else{
39                       break;
40                   }
41               } 
42            }
43        }
44        return best;
45
46    }
47}; 