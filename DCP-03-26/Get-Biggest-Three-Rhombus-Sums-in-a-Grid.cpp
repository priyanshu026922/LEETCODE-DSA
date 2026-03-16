1class Solution {
2public:
3    vector<int> getBiggestThree(vector<vector<int>>& grid) {
4        int n=grid.size();
5        int m=grid[0].size();
6        priority_queue<int,vector<int>,greater<int>>pq;
7        unordered_set<int>s;
8        for(int i=0;i<n;i++){
9            for(int j=0;j<m;j++){
10                
11                //point-1
12                int x=i;
13                int y=j;
14                if(s.count(grid[i][j])==0){
15                    pq.push(grid[i][j]);
16                    s.insert(grid[i][j]);
17                }
18
19                if(pq.size()>3){
20                     pq.pop();
21                }
22                
23                
24                //to correct..........................
25                for(int k=1;k <= min({j, m-j-1, (n-i-1)/2});k++){
26                    //point-2
27                    int sum=grid[i][j];
28                    int new_i1=x+k;
29                    int new_j1=y-k;
30                    
31                    //point-3
32                    int new_i2=x+k;
33                    int new_j2=y+k; 
34                    
35
36                    //point-4
37                    if(x+2*k<n){
38                     int opp_i=x+2*k;
39                     int opp_y=y;
40                     sum+=(grid[new_i1][new_j1]+grid[new_i2][new_j2]+grid[opp_i][opp_y]);
41
42                     for(int d=1;d<k;d++){
43                        sum+=grid[x+d][y-d];
44                     }
45                      for(int d=1;d<k;d++){
46                        sum+=grid[new_i1+d][new_j1+d];
47                     }
48                      for(int d=1;d<k;d++){
49                        sum+=grid[opp_i-d][opp_y+d];
50                     }
51                      for(int d=1;d<k;d++){
52                        sum+=grid[new_i2-d][new_j2-d];
53                     }
54                          if(s.count(sum)==0){
55                            pq.push(sum);
56                            s.insert(sum);
57
58                          }
59
60                            if(pq.size()>3){
61                            pq.pop();
62                            }
63                    }
64                }
65            }
66        }
67
68        vector<int>ans;
69        while(!pq.empty()){
70            int val=pq.top();
71            pq.pop();
72            ans.push_back(val);
73        }
74        sort(rbegin(ans),rend(ans));
75        return ans;
76    }
77};