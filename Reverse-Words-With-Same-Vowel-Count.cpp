1class Solution {
2public:
3    int countV(string s){
4        int n=s.length();
5        int count=0;
6        for(int i=0;i<n;i++){
7            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
8                count++;
9            }
10        }
11        return count;
12    }
13    
14    string reverseWords(string s) {
15        int n=s.length();
16        int i=0;
17        string x="";
18        while(i<n&&s[i]!=' '){
19            x+=s[i];
20            i++;
21        }
22
23        int t=countV(x);
24        cout<<t<<endl;
25        if(i>=n){
26            return s;
27        }
28        i++;
29        int count=0;
30        string ans="";
31        ans+=(x+' ');
32         x="";
33        for(int k=i;k<n;k++){
34            if(s[k]==' '){
35                if(count==t){
36                    reverse(begin(x),end(x));
37                }
38                ans+=(x+' ');
39                count=0;
40                x="";
41                
42            }else{
43                 x+=s[k];
44                 if(s[k]=='a'||s[k]=='e'||s[k]=='i'||s[k]=='o'||s[k]=='u'){
45                   count++;
46                 }
47            }
48        }
49         if(count==t){
50            reverse(begin(x),end(x));
51        }
52            ans+=(x);
53        return ans;
54            }
55};