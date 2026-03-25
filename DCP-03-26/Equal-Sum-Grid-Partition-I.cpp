1class Solution {
2public:
3typedef long long ll;
4    bool canPartitionGrid(vector<vector<int>>& grid) {
5         int n=grid.size();
6         int m=grid[0].size();
7         
8         ll sum=0;
9         for(int i=0;i<n;i++){
10            for(int j=0;j<m;j++){
11                sum=(sum+1LL*grid[i][j]);
12            }
13         }
14         
15         vector<vector<ll>>pref(n,vector<ll>(m,0));
16        for(int i=0;i<n;i++){
17            for(int j=0;j<m;j++){
18              pref[i][j]=1LL*grid[i][j]+(j>0?pref[i][j-1]:0)+(i>0?pref[i-1][j]:0)-(i>0&&j>0?pref[i-1][j-1]:0);
19            }
20        }
21
22        for(int i=0;i<n-1;i++){
23           ll s=pref[i][m-1];
24           ll l=sum-s;
25           if(s==l)return true;
26        }
27
28         for(int j=0;j<m-1;j++){
29           ll s=pref[n-1][j];
30           ll l=sum-s;
31           if(s==l)return true;
32        }
33        return false;
34
35
36    }
37};