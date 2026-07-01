1class Solution {
2public:
3    int minAddToMakeValid(string s) {
4        int n=s.length();
5        int ans=0;
6        int c=0;
7        for(int i=0;i<n;i++){
8            if(s[i]=='(')c++;
9            else c--;
10
11            
12            if(c<0){
13                ans++;
14                c=0;
15            }
16
17        }
18
19
20        ans+=c;
21        return ans;
22    }
23};