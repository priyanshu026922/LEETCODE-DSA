1class Solution {
2private:
3int n;
4public:
5    bool isPalindrome(string s){
6        int i=0;
7        int j=s.length()-1;
8        while(i<j){
9            if(s[i]!=s[j]){
10                return false;
11            }
12            i++;
13            j--;
14        }
15        return true;
16    }
17
18    void solve(string s,int i,vector<vector<string>>&ans,vector<string>&a){
19        if(i==s.length()){
20            ans.push_back(a);
21            return;
22        }
23
24        for(int j=i;j<n;j++){
25           string x=s.substr(i,j-i+1);
26            if(isPalindrome(x)){
27                a.push_back(x);
28                solve(s,j+1,ans,a);
29                a.pop_back();
30            }
31            
32        }
33
34    }
35    vector<vector<string>> partition(string s) {
36        n=s.length();
37        vector<vector<string>>ans;
38        vector<string >a;
39        solve(s,0,ans,a);
40        return ans;
41    }
42};