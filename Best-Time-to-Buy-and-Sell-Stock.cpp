1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int n=prices.size();
5        int maxi=0;
6        int mx=INT_MIN;
7        for(int i=n-1;i>=0;i--){
8            mx=max(mx,prices[i]);
9
10            maxi=max(maxi,mx-prices[i]);
11        }
12        return maxi;
13    }
14};