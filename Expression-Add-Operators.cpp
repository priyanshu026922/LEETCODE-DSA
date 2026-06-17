1class Solution {
2    vector<string>ans;
3    int n;
4    typedef long long ll;
5public:
6
7    void solve(string s,int target,int ind,string path,ll val,ll res){
8        if(ind==s.length()){
9            if(val==target){
10                ans.push_back(path);
11                return;
12            }
13        }
14
15        string curr="";
16        ll num=0;
17        for(int j=ind;j<n;j++){
18            if(j>ind&&s[ind]=='0')return;
19
20            curr+=s[j];
21            num=10*num+s[j]-'0';
22            if(ind==0){
23                solve(s,target,j+1,path+curr,num,num);
24            }else{
25                solve(s,target,j+1,path+"+"+curr,val+num,num);
26                solve(s,target,j+1,path+"-"+curr,val-num,-num);
27                solve(s,target,j+1,path+"*"+curr,val-res+res*num,res*num);
28            }
29        }
30
31    }
32    vector<string> addOperators(string num, int target) {
33        n=num.length();
34        solve(num,target,0,"",0,0);
35        return ans;
36    }
37};