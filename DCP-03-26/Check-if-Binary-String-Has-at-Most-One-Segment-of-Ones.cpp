1class Solution {
2public:
3    bool checkOnesSegment(string s) {
4        int n=s.length();
5        int cnt1=0;
6        int cnt2=0;
7        for(int i=0;i<n;i++){
8            if(s[i]=='1'){
9               cnt1++;
10            }
11        }
12
13        for(int i=0;i<n;i++){
14            if(s[i]=='1'){
15               cnt1--;
16            }else{
17               if(cnt1==0)return true;
18               else return false;
19            }
20        }
21        if(cnt1==0)return true;
22        return false;
23
24       
25    }
26};