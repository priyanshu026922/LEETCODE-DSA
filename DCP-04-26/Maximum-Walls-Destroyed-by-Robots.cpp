1class Solution {
2public:
3int m,n;
4int getNum(int l,int r,vector<int>&walls){
5    auto it1 = lower_bound(walls.begin(), walls.end(), l);
6    auto it2 = upper_bound(walls.begin(), walls.end(), r);
7    return it2 - it1;
8}
9    
10int solve(int i,vector<pair<int,int>>&vec,vector<int>&walls,vector<pair<int,int>>&range,int prev_dir, vector<vector<int>>&dp){
11          if(i>=n){
12            return 0;
13          }
14
15          if(dp[i][prev_dir]!=-1)return dp[i][prev_dir];
16
17           int res=INT_MIN;
18            int l=range[i].first;
19            if(prev_dir==1){//prev robot fired bullets towards right
20                l=max(l,range[i-1].second+1);
21            }
22            
23            int leftT=getNum(l,vec[i].first,walls)+solve(i+1,vec,walls,range,0,dp);
24            int rightT=getNum(vec[i].first,range[i].second,walls)+solve(i+1,vec,walls,range,1,dp);
25             
26            return dp[i][prev_dir]=max(leftT,rightT);
27}
28
29int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
30        n=robots.size();
31        m=walls.size();
32
33        vector<vector<int>>dp(n+1,vector<int>(3,-1));
34
35        vector<pair<int,int>>vec(n);
36        for(int i=0;i<n;i++){
37            vec[i]={robots[i],distance[i]};
38        }
39        
40        sort(begin(vec),end(vec));
41        sort(begin(walls),end(walls));
42
43        vector<pair<int,int>>range(n);
44        for(int i=0;i<n;i++){
45            int left=(i==0)?1:vec[i-1].first+1;
46            int right=(i==n-1)?1e9:vec[i+1].first-1;
47
48            int L=max(left,vec[i].first-vec[i].second);
49            int R=min(right,vec[i].first+vec[i].second);
50            range[i]={L,R};
51        }
52        //dir
53        //0--->left
54        //1--->right
55        return solve(0,vec,walls,range,0,dp);
56}
57};