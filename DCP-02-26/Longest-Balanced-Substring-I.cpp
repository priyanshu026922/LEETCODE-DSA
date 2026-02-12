1class Solution {
2public:
3    int longestBalanced(string s) {
4      int n=s.length();
5      int maxi=0;
6      for(int i=0;i<n;i++){
7        vector<int>count(26,0);
8        for(int j=i;j<n;j++){
9            count[s[j]-'a']++;
10            int val=count[s[j]-'a'];
11            bool t=true;
12            for(int k=0;k<26;k++){
13                if(count[k]>0){
14                    if(count[k]!=val){
15                       t=false;
16                       break;
17                    }
18                }
19            }
20            if(t){
21                maxi=max(maxi,j-i+1);
22            }
23        }
24      }
25      
26      return maxi;
27    }
28};