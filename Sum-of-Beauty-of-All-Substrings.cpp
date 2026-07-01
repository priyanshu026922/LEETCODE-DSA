1class Solution {
2public:
3    int beautySum(string s) {
4        int n=s.length();
5      
6       int sum=0;
7        for(int i=0;i<n;i++){
8            unordered_map<char,int>mp;
9            for(int j=i;j<n;j++){
10                mp[s[j]]++;
11                int maxi=INT_MIN;
12            int mini=INT_MAX;
13            for(auto it:mp){
14                maxi=max(maxi,it.second);
15                 mini=min(mini,it.second);
16            }
17                sum+=(maxi-mini);
18            }
19        }
20        return sum;
21    }
22};