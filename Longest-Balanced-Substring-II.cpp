1class Solution {
2public:
3
4int n;
5int  solve2(string &s,char ch1,char ch2){
6    unordered_map<int,int>mp;
7    int cnt1=0;//a
8    int cnt2=0;//b
9    int maxi=0;
10    for(int i=0;i<n;i++){
11        if(s[i]==ch1){
12             cnt1++;
13        }else if(s[i]==ch2){
14            cnt2++;
15        }else{
16            mp.clear();
17            cnt2=0;
18            cnt1=0;
19            continue;
20        }
21
22        if(cnt1==cnt2){
23            maxi=max(maxi,cnt1+cnt2);
24        }
25
26        if(mp.find(cnt1-cnt2)!=mp.end()){
27            maxi=max(maxi,i-mp[cnt1-cnt2]);
28        }else{
29            mp[cnt1-cnt2]=i;
30        }
31    }
32    return maxi;
33}
34
35int  solve3(string &s){
36    map<pair<int,int>,int>mp;
37    int cnt1=0;
38    int cnt2=0;
39    int cnt3=0;
40    int maxi=0;
41    for(int i=0;i<n;i++){
42        if(s[i]=='a'){
43            cnt1++;
44        }else if(s[i]=='b'){
45            cnt2++;
46        }else{
47            cnt3++;
48        }
49        if(cnt1==cnt2&&cnt2==cnt3){
50            maxi=max(maxi,cnt1+cnt2+cnt3);
51        }
52        if(mp.find({cnt1-cnt2,cnt1-cnt3})!=mp.end()){
53            maxi=max(maxi,i-mp[{cnt1-cnt2,cnt1-cnt3}]);
54        }else{
55            mp[{cnt1-cnt2,cnt1-cnt3}]=i;
56        }
57    }
58    return maxi;
59}
60
61
62
63    int longestBalanced(string s) {
64     n=s.length();
65
66        //CASE -01
67        //ALL SAME
68        int maxi=0;
69        int cnt1=1;
70        for(int i=1;i<n;i++){
71            if(s[i]==s[i-1]){
72                cnt1++;
73            }else{
74                maxi=max(maxi,cnt1);
75                cnt1=1;
76            }
77        }
78         maxi=max(maxi,cnt1);
79        
80
81
82
83        //CASE-02
84        //2 DIFFERENT
85
86        maxi=max(maxi,solve2(s,'a','b'));
87        maxi=max(maxi,solve2(s,'a','c'));
88        maxi=max(maxi,solve2(s,'b','c'));
89        
90
91
92        maxi=max(maxi,solve3(s));
93
94
95        //CASE-03
96        //3 DIFFERENT
97        return maxi;
98    }
99};