1class Solution {
2public:
3int largestRecArea(vector<int>&hist){
4        stack<int>st;//we are storing indices such that values in hist are in inc. order
5        int maxA=0;
6        int n=hist.size();
7        for(int i=0;i<=n;i++){
8            while(!st.empty()&&(i==n||hist[st.top()]>hist[i])){
9                int h=hist[st.top()];
10                st.pop();
11                int w;
12                if(st.empty()){
13                    w=i;//we are taking the full width till that index i....
14                }else{
15                    w=i-st.top()-1;
16                
17                }
18                maxA=max(maxA,w*h);
19            }
20            st.push(i);
21        }
22        return maxA;
23}
24
25    int maximalRectangle(vector<vector<char>>& matrix) {
26        int n=matrix.size();
27        int m=matrix[0].size();
28        int maxA=0;
29        vector<int>height(m,0);
30        for(int i=0;i<n;i++){
31            for(int j=0;j<m;j++){
32                if(matrix[i][j]=='1')height[j]++;
33                else height[j]=0;
34            }
35            maxA=max(maxA,largestRecArea(height));
36        }
37        return maxA;
38    }
39};