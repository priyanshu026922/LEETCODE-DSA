1class Solution {
2public:
3    void computeLPS(string &a,vector<int>&lps){
4         int m=a.length();
5        lps[0]=0;
6        int i=1;
7        int len=0;
8
9        while(i<m){
10            if(a[i]==a[len]){
11                len++;
12                lps[i]=len;
13                i++;
14            }else{
15                if(len!=0)len=lps[len-1];
16                else i++;
17            }
18
19        }
20    }
21    string shortestPalindrome(string s) {
22       
23        string rev=s;
24
25        reverse(begin(rev),end(rev));
26        string a=s+'#'+rev;
27        int m=a.length();
28        vector<int>lps(m+1);
29        computeLPS(a,lps);
30
31        int common=lps[m-1];
32
33
34        string ans=rev+s.substr(common);
35        return ans;
36        
37
38    }
39};