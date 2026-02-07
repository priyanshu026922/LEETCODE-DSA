1class Solution {
2public:
3    int minimumDeletions(string s) {
4        int n=s.length();
5        if(n==1)return 0;
6        vector<int>v1(n);//for b
7        vector<int>v2(n);//for a
8        int cnt1=0;
9        int cnt2=0;
10
11        for(int i=0;i<n;i++){
12           
13            v1[i]=cnt1;
14             if(s[i]=='b'){
15                cnt1++;
16            }
17        }
18
19        for(int i=n-1;i>=0;i--){
20            
21            v2[i]=cnt2;
22            if(s[i]=='a'){
23                cnt2++;
24            }
25        }
26
27        int mini=n;
28         for(int i=0;i<n;i++){
29              mini=min(mini,v1[i]+v2[i]);
30         }
31        return mini;
32    } 
33};