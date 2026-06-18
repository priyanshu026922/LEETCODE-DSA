1  class Solution {
2public:
3    typedef long long ll;
4    char processStr(string s, ll k) {
5        int n=s.length();
6        //here cosntraint given are :n<=10^5
7        //so we target t.c around O(n),O(nlogn),O(nsqrt(n)),,or anything of smaller T.C
8        ll len=0;
9        //bvrute appraoch here would is just simultion
10        for(int i=0;i<n;i++){
11            if(s[i]=='*'){
12               len=max(0LL,len-1LL);
13            }else if(s[i]=='#'){
14               len=2LL*len;
15            }else if(s[i]=='%'){
16                continue;
17                //proble  is revversing the string 
18                //because it would take a T.C of O(N)
19            }else{
20                len++;
21            }
22        }
23
24        if(len==0||k>=len)return '.';
25        
26
27        for(int i=n-1;i>=0;i--){
28             if(s[i]=='*'){
29               len++;
30            }else if(s[i]=='#'){
31               len=len/2;
32               if(k>=len)k=k-len;
33            }else if(s[i]=='%'){
34                k=(len-k-1);
35                //proble  is revversing the string 
36                //because it would take a T.C of O(N)
37            }else{
38                len--;
39            }
40            
41            if(len==k){
42                // cout<<len<<endl;
43                return s[i];
44            }
45        }
46       
47       return '.';
48
49    }
50};