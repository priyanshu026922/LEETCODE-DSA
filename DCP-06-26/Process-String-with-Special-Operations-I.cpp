1class Solution {
2public:
3    string processStr(string s) {
4        int n=s.length();
5        string res="";
6        for(auto &it:s){
7             if(it=='*'){
8               if(!res.empty()){
9                  res.pop_back();
10               }
11             }else if(it=='#'){
12                  if(!res.empty()){
13                    res+=res;
14                  }
15             }else if(it=='%'){
16                 reverse(begin(res),end(res));
17             }else{
18               res+=it;
19             }
20
21
22        }
23        return res;
24    }
25};