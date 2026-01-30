1class Solution {
2public:
3    typedef long long ll;
4    ll val=1e10;
5    unordered_map<string,vector<pair<string,ll>>>adj;
6    vector<ll>dpMemo;
7    string sourceStr;
8    string targetStr;
9    set<int>validLen;
10
11    unordered_map<string,unordered_map<string,ll>>dkMemo;
12
13    ll dk(string src,string tar){
14
15        if(dkMemo[src].count(tar)){
16            return dkMemo[src][tar];
17        }
18
19        priority_queue<pair<ll,string>,vector<pair<ll,string>>,greater<pair<ll,string>>>pq;
20        unordered_map<string,ll>res;
21        res[src]=0;
22        pq.push({0,src});
23        while(!pq.empty()){
24            ll currCost=pq.top().first;
25            string node=pq.top().second;
26            pq.pop();
27            if(node==tar){
28                break;
29            }
30
31            for(auto &edge:adj[node]){
32                string adjNode=edge.first;
33                ll edgeCost=edge.second;
34                if(!res.count(adjNode)||currCost+edgeCost<res[adjNode]){
35                    res[adjNode]=currCost+edgeCost;
36                    pq.push({currCost+edgeCost,adjNode});
37                }
38            }
39        }
40
41        ll final=res.count(tar)?res[tar]:val;
42        return dkMemo[src][tar]=final;
43    }
44
45
46
47    ll solve(int idx){
48        if(idx>=sourceStr.length()){
49            return 0;
50        }
51
52        if(dpMemo[idx]!=-1)return dpMemo[idx];
53
54        ll miniCost=val;
55        if(sourceStr[idx]==targetStr[idx]){//IF MATCHED ,WE HAVE A OPTION TO FIND POSSIBLE ANS IN ANY NEXT STEP ,SKIPPING THIS STEP!!!!!!
56            miniCost=solve(idx+1);
57        }
58
59        for(auto &len:validLen){
60            if(idx+len>sourceStr.length()){
61                break;
62            }
63            string src=sourceStr.substr(idx,len);
64            string tar=targetStr.substr(idx,len);
65
66            if(!adj.count(src)){
67                continue;
68            }
69
70            ll minPath=dk(src,tar);
71
72
73
74            if(minPath==1e10)continue;
75
76            miniCost=min(miniCost,minPath+solve(idx+len));
77        }
78        return dpMemo[idx]=miniCost;
79    }
80
81    ll minimumCost(string source, string target, vector<string>& original, vector<string>&changed, vector<int>& cost) {
82          sourceStr=source;
83          targetStr=target;
84
85          dpMemo.assign(10001,-1);//FOR MEMOIZING THE SOLUTION
86
87          for(int i=0;i<original.size();i++){
88               adj[original[i]].push_back({changed[i],cost[i]});//ADJACENY MATRIX
89          }
90
91          for(auto &it:original){ //to get possible length of original array string
92            validLen.insert(it.length());
93          }
94
95          ll res=solve(0);
96          return res==val?-1:res;
97    } 
98};