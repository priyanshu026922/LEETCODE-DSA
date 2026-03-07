1class Solution {
2public:
3    int minFlips(string s) {
4        int n=s.length();
5        s=(s+s);
6        int i=0;
7        int j=0;
8        string s1,s2;
9        for(int i=0;i<2*n;i++){
10            s1+=((i%2==0)?'0':'1');
11            s2+=((i%2==0)?'1':'0');
12        }
13        int mini=INT_MAX;
14        int flip1=0;
15        int flip2=0;
16        while(j<2*n){
17            if(s[j]!=s1[j]){
18                flip1++;
19            }
20            if(s[j]!=s2[j]){
21                flip2++;
22            }
23
24            if(j-i+1>n){
25                if(s[i]!=s1[i]){
26                    flip1--;
27                }
28                if(s[i]!=s2[i]){
29                    flip2--;
30                }
31                i++;
32            }
33
34          if(j-i+1==n) mini=min({mini,flip1,flip2});
35            j++;
36        }
37        return mini;
38    }
39};