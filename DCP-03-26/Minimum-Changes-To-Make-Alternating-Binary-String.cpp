1class Solution {
2public:
3    int minOperations(string s) {
4        
5        int n=s.length();
6        int cnt1=0,cnt2=0;
7        for(int i=0;i<n;i++){
8            if(i%2==0){
9                if(s[i]=='1'){
10                    continue;
11                }else{
12                    cnt1++;
13                }
14            }else{
15                if(s[i]=='0'){
16                    continue;
17                }else{
18                    cnt1++;
19                }
20            }
21        }
22        for(int i=0;i<n;i++){
23            if(i%2==0){
24                if(s[i]=='0'){
25                    continue;
26                }else{
27                    cnt2++;
28                }
29            }else{
30                if(s[i]=='1'){
31                    continue;
32                }else{
33                    cnt2++;
34                }
35            }
36        }
37        return min(cnt1,cnt2);
38
39
40    }
41};