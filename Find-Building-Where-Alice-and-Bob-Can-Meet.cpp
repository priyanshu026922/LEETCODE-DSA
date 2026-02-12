1class Solution {
2public:
3
4void buildTree(vector<int>&heights,int i,int l,int r,vector<int>&segTree){
5    if(l==r){
6         segTree[i]=l;
7         return;
8    }
9   
10    int mid=(l+r)/2;
11    buildTree(heights,2*i+1,l,mid,segTree);
12    buildTree(heights,2*i+2,mid+1,r,segTree);
13    int left=segTree[2*i+1];
14    int right=segTree[2*i+2];
15
16    segTree[i]=((heights[left]>=heights[right])?left:right);
17    return;
18}
19
20int getQuery(int a,int b,int i,int l,int r,vector<int>&segTree,vector<int>&heights){
21   if(l>b||r<a)return -1;
22     if(l>=a&&r<=b){
23        return segTree[i];
24     }
25
26      int mid=(l+r)/2;
27      int left=getQuery(a,b,2*i+1,l,mid,segTree,heights);
28      int right=getQuery(a,b,2*i+2,mid+1,r,segTree,heights);
29     if(left==-1)return right;
30     if(right==-1)return left;
31
32     if(heights[left]>=heights[right]){
33        return left;
34     }
35     return right;
36}
37
38int queryIndex(int a,int b,int n,vector<int>&segTree,vector<int>&heights){
39    return getQuery(a,b,0,0,n-1,segTree,heights);
40    
41}
42
43vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
44        int n=heights.size();
45        
46        vector<int>segTree(4*n+1);
47
48        buildTree(heights,0,0,n-1,segTree);
49
50
51        vector<int>ans;
52        for(auto it:queries){
53            int l=it[0];
54            int r=it[1];
55            
56           int maxiIdx=max(l,r);
57           int miniIdx=min(l,r);
58
59           if(l==r){
60             ans.push_back(l);
61             continue;
62           }
63
64           if(heights[maxiIdx]>heights[miniIdx]){
65              ans.push_back(maxiIdx);
66              continue;
67           }
68
69
70            int i=maxiIdx+1;
71            int j=n-1;
72            int x=INT_MAX;
73            while(i<=j){
74                int mid=(i+j)/2;
75                int ind1=queryIndex(i,mid,n,segTree,heights);//(start,end,l,r,i,segTree,heights)
76                // int ind2=queryIndex(mid+1,n-1,i,n-1,)
77                
78                if(ind1!=-1&&heights[ind1]>max(heights[l],heights[r])){
79                     x=min(x,ind1);
80                     j=mid-1;
81                }else {
82                     i=mid+1;
83                }
84            }
85            if(x==INT_MAX){
86                ans.push_back(-1);
87                
88            }
89            else {
90             ans.push_back(x);
91            }
92        }
93        return ans;
94      }
95};