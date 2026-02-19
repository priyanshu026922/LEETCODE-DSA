1class Solution {
2public:
3    int countBinarySubstrings(string s) {
4        int n=s.length();
5        int curr=1;
6        int prev=0;
7        int ans=0;
8        for(int i=1;i<n;i++){
9            if(s[i]==s[i-1]){
10                curr++;
11            }else{
12                 ans+=min(curr,prev);
13                prev=curr;
14                curr=1;
15            }
16           
17        }
18        return ans+min(prev,curr);
19    }
20};