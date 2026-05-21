1class Solution {
2public:
3    int n;
4    vector<int>findnse(vector<int>& h){
5        vector<int>ans(n);
6        stack<int>s;
7        for(int i=n-1;i>=0;i--){
8           int val=h[i];
9
10           while(!s.empty()&&h[i]<=h[s.top()]){
11            s.pop();
12           }
13           if(s.empty()){
14              ans[i]=n;
15           }else{
16              ans[i]=s.top();
17           }
18           s.push(i);
19        }
20        return ans;
21    }
22    vector<int>findpse(vector<int>&h){
23         vector<int>ans(n);
24        stack<int>s;
25        for(int i=0;i<n;i++){
26           int val=h[i];
27
28           while(!s.empty()&&h[i]<=h[s.top()]){
29            s.pop();
30           }
31           if(s.empty()){
32              ans[i]=-1;
33           }else{
34              ans[i]=s.top();
35           }
36           s.push(i);
37        }
38        return ans;
39    }
40
41    int largestRectangleArea(vector<int>& heights) {
42         n=heights.size();
43        vector<int>nse=findnse(heights);
44        vector<int>pse=findpse(heights);
45        
46        int maxi=0;
47        for(int i=0;i<n;i++){
48          maxi=max(maxi,(nse[i]-pse[i]-1)*heights[i]);
49        }
50
51       
52       
53       return maxi;
54    }
55};