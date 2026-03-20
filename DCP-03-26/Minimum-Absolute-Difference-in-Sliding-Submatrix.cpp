1class Solution {
2public:
3    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid,int k){
4        int n=grid.size();
5        int m=grid[0].size();
6        vector<vector<int>>ans(n-k+1,vector<int>(m-k+1));
7        for(int i=0;i<=n-k;i++){
8            for(int j=0;j<=m-k;j++){
9                set<int>s;
10               
11                // if(i+k<n&&j+k<m){
12                    for(int x=i;x<i+k;x++){
13                        for(int y=j;y<j+k;y++){
14                            s.insert(grid[x][y]);
15                        }
16                    }
17                // } 
18                    int mini=INT_MAX;
19                    for(auto it:s){
20                        for(auto itt:s){
21                            if(it!=itt){
22                                mini=min(mini,abs(itt-it));
23                            }
24                        }
25                    }
26                    if(mini==INT_MAX){
27                        ans[i][j]=0;
28                    }
29                    else ans[i][j]=mini;
30                // auto it=s.begin();
31                // int val=*it;
32                // s.erase(*it);
33                // auto itt=s.begin();
34                // ans[i][j]=*itt-val;
35            }
36        }
37        return ans;
38    }
39};