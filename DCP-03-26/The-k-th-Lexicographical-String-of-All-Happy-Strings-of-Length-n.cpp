1class Solution {
2public:
3    void solve(string s,char last,int n, vector<string>&ans){
4        if(s.length()==n){
5            ans.push_back(s);
6            return;
7        }
8        if(last!='a'){
9            solve(s+'a','a',n,ans);
10        }
11        if(last!='b'){
12            solve(s+'b','b',n,ans);
13        }
14         if(last!='c'){
15            solve(s+'c','c',n,ans);
16        }
17
18    }
19    string getHappyString(int n, int k){
20        vector<string>ans;
21        solve("",'~',n,ans);
22        if(ans.size()<k){
23            return "";
24        }
25        sort(begin(ans),end(ans));
26        // for(int i=0;i<ans.size();i++){
27        //     cout<<ans[i]<<" ";
28        // }
29        // cout<<endl;
30        return ans[k-1];
31    }
32};