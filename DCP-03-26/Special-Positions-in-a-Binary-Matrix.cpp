1class Solution {
2public:
3    int numSpecial(vector<vector<int>>& mat) {
4        int n=mat.size();
5        int m=mat[0].size();
6        vector<int>r(n,0);
7        vector<int>c(m,0);
8        for(int i=0;i<n;i++){
9            for(int j=0;j<m;j++){
10                if(mat[i][j]==0){
11                    r[i]++;
12                    c[j]++;
13                }
14            }
15        }
16        int cnt=0;
17        for(int i=0;i<n;i++){
18            for(int j=0;j<m;j++){
19               if(mat[i][j]==1){
20                 int val1=n-1;
21                 int val2=m-1;
22                 if(r[i]==val2&&c[j]==val1){
23                    cnt++;
24                 }
25               }
26            }
27        }
28        return cnt;
29    }
30};