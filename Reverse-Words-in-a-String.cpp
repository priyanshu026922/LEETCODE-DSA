1class Solution {
2public:
3    string reverseWords(string s) {
4        int n=s.length();
5        int l=0;
6        int r=0;
7        int i=0;
8        
9        reverse(begin(s),end(s));
10        while(i<n){
11           
12           while(i<n&&s[i]==' '){
13             i++;
14           }
15
16           if(i==n)break;
17
18          while(i<n&&s[i]!=' '){
19            s[r]=s[i];
20            r++;
21            i++;
22          }
23
24
25          reverse(begin(s)+l,begin(s)+r);
26
27          s[r]=' ';
28          r++;
29          l=r;
30          i++;
31        }
32        s.resize(r-1);
33        return s;
34    }
35};