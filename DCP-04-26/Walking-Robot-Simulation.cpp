1class Solution {
2public:
3int n;
4    // int solve(vector<int>&c,vector<vector<int>>&o,set<pair<int,int>>&st,int ind,int i,int j,int dir){
5    //     if(ind==n){
6    //        return INT_MAX;
7    //     }
8
9    //     int t=i*i+j*j;
10    //     int maxi=t;
11    //     if(c[i]>0){
12    //         int val=c[i];
13    //         // for(int k=1;k<=val;k++){
14                 
15    //         // }
16    //     }else{
17    //          int val=
18    //     }
19
20    //     maxi=max(maxi,solve(c,o,st,ind+1,i+k1,j+l,dir));
21    //     return maxi;
22    // }
23
24    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
25        n=commands.size();
26
27        set<pair<int,int>>st;
28        for(auto &it:obstacles){
29            st.insert({it[0],it[1]});
30        }
31        
32        int maxi=INT_MIN;
33        pair<int,int>dir={0,1};
34        int x=0;
35        int y=0;
36        for(int k=0;k<n;k++){
37            int val=commands[k];
38            if(val==-2){
39             dir={-dir.second,dir.first};
40            }else if(val==-1){
41              dir={dir.second,-dir.first};
42            }else{
43                for(int s=0;s<val;s++){
44                    int newX=x+dir.first;
45                    int newY=y+dir.second;
46
47                    if(st.count({newX,newY})>0){
48                        break;
49                    }
50                    x=newX;
51                    y=newY;
52                }
53            }
54            maxi=max(maxi,x*x+y*y);
55        }
56
57        return maxi;
58    }
59};