1class Solution {
2public:
3    typedef long long ll;
4    ll val=1e10;
5    unordered_map<string,vector<pair<string,ll>>>adj;
6    vector<ll>dpMemo;
7    string sourceStr;
8    string targetStr;
9    set<int>validLen;
10    ll dk(string src,string tar){
11        priority_queue<pair<ll,string>,vector<pair<ll,string>>,greater<pair<ll,string>>>pq;
12        unordered_map<string,ll>res;
13        res[src]=0;
14        pq.push({0,src});
15        while(!pq.empty()){
16            ll currCost=pq.top().first;
17            string node=pq.top().second;
18            pq.pop();
19            if(node==tar){
20                break;
21            }
22
23            for(auto &edge:adj[node]){
24                string adjNode=edge.first;
25                ll edgeCost=edge.second;
26                if(!res.count(adjNode)||currCost+edgeCost<res[adjNode]){
27                    res[adjNode]=currCost+edgeCost;
28                    pq.push({currCost+edgeCost,adjNode});
29                }
30            }
31        }
32
33        ll final=res.count(tar)?res[tar]:val;
34        return final;
35    }
36    ll solve(int idx){
37        if(idx>=sourceStr.length()){
38            return 0;
39        }
40
41        if(dpMemo[idx]!=-1)return dpMemo[idx];
42
43        ll miniCost=val;
44        if(sourceStr[idx]==targetStr[idx]){
45            miniCost=solve(idx+1);
46        }
47
48        for(auto &len:validLen){
49            if(idx+len>sourceStr.length()){
50                break;
51            }
52            string src=sourceStr.substr(idx,len);
53            string tar=targetStr.substr(idx,len);
54
55            if(!adj.count(src)){
56                continue;
57            }
58            ll minPath=dk(src,tar);
59            if(minPath==1e10)continue;
60
61            miniCost=min(miniCost,minPath+solve(idx+len));
62        }
63        return dpMemo[idx]=miniCost;
64    }
65
66    ll minimumCost(string source, string target, vector<string>& original, vector<string>&changed, vector<int>& cost) {
67          sourceStr=source;
68          targetStr=target;
69
70          dpMemo.assign(10001,-1);
71
72          for(int i=0;i<original.size();i++){
73            adj[original[i]].push_back({changed[i],cost[i]});
74          }
75
76          for(auto &it:original){
77            validLen.insert(it.length());
78          }
79          ll res=solve(0);
80          return res==val?-1:res;
81    }
82};