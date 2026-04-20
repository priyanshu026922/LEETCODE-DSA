1class Solution {
2public:
3    int maxDistance(vector<int>& colors) {
4        int n=colors.size();
5        int maxi=INT_MIN;
6        for(int i=0;i<n;i++){
7            for(int j=n-1;j>=0;j--){
8                if(colors[i]!=colors[j]){
9                   maxi=max(maxi,abs(j-i));
10                   break;
11                }
12            }
13        }
14        return maxi;
15    }
16};