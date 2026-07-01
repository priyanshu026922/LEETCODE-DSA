1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4        int i=0;
5        int j=0;
6        int n=s.length();
7        int m=0;
8        vector<int>vec(26,0);
9        int maxi=0;
10        while(j<n){
11           vec[s[j]-'A']++;
12           
13           
14           for(int k=0;k<26;k++){
15               maxi=max(maxi,vec[k]);
16           }
17           
18           int len=j-i+1;
19           while(i<n&&len-maxi>k){
20              vec[s[i]-'A']--;
21              for(int k=0;k<26;k++){
22                 maxi=max(maxi,vec[k]);
23              }
24              i++;
25              len=j-i+1;
26           }
27
28
29           m=max(m,j-i+1);
30           j++;
31        }
32        return m;
33    }
34};