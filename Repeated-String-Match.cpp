1class Solution {
2public:
3   bool kmp(string &a,string &b){
4    int  n=a.length();
5    int  m=b.length();
6
7       vector<int>lps(m,0);
8        int i=1;
9        int len=0;
10        while(i<m){
11            if(b[i]==b[len]){
12                len++;
13                lps[i]=len;
14                i++;
15            }else{
16               if(len!=0) len=lps[len-1];
17               else{
18                   i++;
19               }
20            }
21        }
22
23
24        i=0;
25        int j=0;
26        while(i<n){
27            if(a[i]==b[j]){
28                i++;
29                j++;
30            }
31
32            if(j==m){
33               return true;
34            }
35
36            else if(i<n&&a[i]!=b[j]){
37               if(j!=0)j=lps[j-1];
38               else i++;
39            }
40        }
41        return false;
42   }
43
44    int repeatedStringMatch(string a, string b) {
45        int  m=b.length();
46        
47
48        string c="";
49        int cnt=0;
50        while(c.length()<m){
51            c+=a;
52            cnt++;
53        }
54        
55
56
57        if(kmp(c,b)){
58            return cnt;
59        }
60     
61        string s=c+a;
62        if(kmp(s,b)){
63            return cnt+1;
64        }
65
66        return -1;
67
68
69    }
70};