1class Solution {
2public:
3    string addBinary(string a, string b) {
4        //LET SUPPOSE a.length()>b.length()
5        if(b.length()>a.length()){
6            swap(a,b);
7        }
8        int n=a.length();
9        int m=b.length();
10        int val=n-m;
11        string s="";
12        for(int i=0;i<val;i++){
13               s+='0';
14        }
15        for(int i=0;i<m;i++){
16            s+=b[i];
17        }
18        cout<<a<<":::: "<<s<<endl;
19         
20        string ans=a;
21        int carry=0;
22        for(int i=n-1;i>=0;i--){
23            if(a[i]=='1'&&s[i]=='1'){
24               if(carry==1){
25                  a[i]='1';
26               }else{
27                  a[i]='0';
28               }
29                carry=1;
30            }else if(a[i]=='1'&&s[i]=='0'){
31                if(carry==1){
32                  a[i]='0';
33                  carry=1;
34                }else{
35                  a[i]='1';
36                  carry=0;
37                }
38            }else if(a[i]=='0'&&s[i]=='1'){
39                if(carry==1){
40                  a[i]='0';
41                  carry=1;
42                }else{
43                  a[i]='1';
44                  carry=0;
45                }
46            }else{
47                 if(carry==1){
48                  a[i]='1';
49                }else{
50                  a[i]='0';
51                }
52                 carry=0;
53            }
54        }
55
56        if(carry==1){
57            reverse(begin(a),end(a));
58            a+='1';
59             reverse(begin(a),end(a));
60        }
61        return a;
62    }
63};