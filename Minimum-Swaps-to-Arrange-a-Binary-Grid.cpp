1class Solution {
2public:
3    int minSwaps(vector<vector<int>>& grid) {
4        int n=grid.size();
5        int cnt=0;
6        vector<int>endZeroes(n,0);
7        for(int i=0;i<n;i++){
8            int c=0;
9            for(int j=n-1;j>=0;j--){
10                if(grid[i][j]==0)c++;
11                else break;
12            }
13            endZeroes[i]=c;
14        }
15        for(int i=0;i<n;i++){
16            int need=n-i-1;
17            int j=i;
18            while(j<n&&endZeroes[j]<need){
19                j++;
20            }
21            if(j==n){
22                  return -1;
23            }
24            cnt+=(j-i);
25            while(j>i){
26                swap(endZeroes[j],endZeroes[j-1]);
27                j--;
28            }
29        }
30        return cnt;
31    }
32};