1class Solution {
2public:
3    int longestBalanced(string s) {
4        int n=s.length();
5        int t1=0;
6        for(char ch:s){
7            if(ch=='1')t1++;
8        }
9
10        int t0=n-t1;
11
12        int s1=0;//curr sum
13        unordered_map<int,int>mp;//prefix sum
14        mp[0]=-1;
15        unordered_map<int,int>mp0;//prefix such as 0 exist in left side
16        unordered_map<int,int>mp1;//prefix such as 1 exist in it
17
18        int c1=0,c0=0;
19        int ans=0;
20
21        for(int i=0;i<n;i++){
22            if(s[i]=='1'){
23                c1++;
24                s1++;
25            }else{
26                c0++;
27                s1--;
28            }
29            if(mp.find(s1)!=mp.end()){
30                ans=max(ans,i-mp[s1]);
31            }
32            
33
34            int ta=s1-2;//replace 1->0:sum =====sum-2
35            if(mp.find(ta)!=mp.end()){
36                if(t0>c0)  //we can find zero on right side
37                {
38                    ans=max(ans,i-mp[ta]);
39                }
40                //right side mai nhi bacha zero ab swap ke liye
41                else if(mp0.find(ta)!=mp0.end()){//prefix with sum ta and it has 0 
42                    ans=max(ans,i-mp0[ta]);
43                }
44            }
45
46            ta=s1+2;
47            if(mp.find(ta)!=mp.end()){
48                if(t1>c1)  //we can find one on right side
49                {
50                    ans=max(ans,i-mp[ta]);
51                }
52                //right side mai nhi bacha zero ab swap ke liye
53                else if(mp1.find(ta)!=mp1.end()){//prefix with sum ta and it has 0 
54                    ans=max(ans,i-mp1[ta]);
55                }
56            }
57
58            if(mp.find(s1)==mp.end()){
59                mp[s1]=i;
60            }
61            if(c0>0&&mp0.find(s1)==mp0.end()){
62                mp0[s1]=i;
63            }
64             if(c1>0&&mp1.find(s1)==mp1.end()){
65                mp1[s1]=i;
66            }
67        }
68        return ans;
69
70    }
71};