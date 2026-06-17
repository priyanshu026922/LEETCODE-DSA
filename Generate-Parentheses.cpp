1class Solution {
2public:
3    void solve(string s,int n,int cnt,vector<string>&a){
4        if(cnt>n){
5            return ;
6        }
7
8       if(cnt==0&&n==0){
9          a.push_back(s);
10          return;
11       }
12
13        if(n>cnt){
14            s+='(';
15            solve(s,n,cnt+1,a);
16            s.pop_back();
17        }
18
19        if(cnt>0){
20            s+=')';
21            solve(s,n-1,cnt-1,a);
22            s.pop_back();
23        }
24    }
25    vector<string> generateParenthesis(int n) {
26        vector<string>a;
27        solve("",n,0,a);
28        return a;
29    }
30};