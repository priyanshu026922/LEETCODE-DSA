1class Solution {
2public:
3    int minOperations(string s) {
4        int n=s.length();
5        string req=s;
6        sort(begin(req),end(req));
7        
8        if(req==s)return 0;
9
10        if(n==2)return -1;
11
12        if(req[0]==s[0]||req[n-1]==s[n-1]){
13            return 1;
14        }
15
16      
17        int mx = -1; int mn = 1000;
18        for(auto x:s){
19            mx = max(mx,(int)x);
20            mn = min(mn,(int)x);
21        }
22
23        if(s[0]==mx||s[n-1]==mn)
24        {
25            for(int i=1;i<n-1;i++){
26                if((int)s[i]==mx||(int)s[i]==mn){
27                    return 2;
28                }
29            }
30            return 3;
31        }
32        
33       
34        return 2;
35
36    }
37
38};