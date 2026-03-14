1class Solution {
2public:
3    void solve(string s,char last,int n, string &res,int &cnt,int k){
4        if(s.length()==n){
5            cnt++;
6            if(cnt==k){
7                res=s;
8            }
9            return;
10        }
11
12        for(char ch='a';ch<='c';ch++){
13            if(ch!=last){
14                s+=ch;;
15                solve(s,ch,n,res,cnt,k);
16                s.pop_back();
17            }
18        }
19    }
20
21    string getHappyString(int n, int k){
22        string res="";
23        int cnt=0;
24        solve("",'~',n,res,cnt,k);
25        return res;
26    }
27};