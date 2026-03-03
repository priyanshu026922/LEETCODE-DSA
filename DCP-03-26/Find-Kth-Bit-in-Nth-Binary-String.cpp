1class Solution {
2public:
3    char findKthBit(int n, int k) {
4        string s="0";
5        for(int i=2;i<=n;i++){
6            string t=s;
7            for(int i=0;i<t.length();i++){
8                if(t[i]=='0')t[i]='1';
9                else t[i]='0';
10            }
11            reverse(begin(t),end(t));
12            string s1=s+'1'+t;
13            s=s1;
14        }
15        return s[k-1];
16    }
17};