1class Solution {
2private:
3int n;
4public:
5vector<int>dp;
6vector<vector<int>>p;
7   bool isPalindrome(string &s,int i,int j){
8      while(i<j){
9        if(s[i]!=s[j])return false;
10        i++;
11        j--;
12      }
13      return true;
14   }
15
16    int solve(string &s,int i){
17        
18        if(i==s.length()){
19            return 0;
20        }
21        
22        if(dp[i]!=-1)return dp[i];
23      
24        int maxi=n;
25        for(int j=i;j<n;j++){
26            if(isPalindrome(s,i,j)){
27                maxi=min(maxi,1+solve(s,j+1));
28            }
29        }
30       
31         return dp[i]=maxi;
32    }
33
34    int minCut(string s) {
35        n=s.length();
36
37        
38        dp.assign(n+1,-1);
39
40        
41        return solve(s,0)-1;
42    }
43};