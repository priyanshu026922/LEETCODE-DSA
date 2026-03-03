1class Solution {
2public:
3    int minimumOR(vector<vector<int>>& grid) {
4        int a=(1<<20)-1;
5        for(int bit=19;bit>=0;bit--){
6            int ans=a^(1<<bit);
7            bool pos=true;
8            for(auto &r:grid){
9                bool sub=false;
10                for(auto x:r){
11                    if((ans|x)==ans)sub=true;
12                }
13                if(!sub)pos=false;
14            }
15            if(!pos)continue;
16            a=ans;
17        }
18        return a;
19    }
20};