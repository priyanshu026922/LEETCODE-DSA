1class Solution {
2public:
3    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
4      int m=buildings.size();
5       unordered_map<int,set<int>>mp_x;
6       unordered_map<int,set<int>>mp_y;
7       for(int i=0;i<m;i++){
8            int x=buildings[i][0];
9            int y=buildings[i][1];
10            mp_x[x].insert(y);
11            mp_y[y].insert(x);
12       }
13       int count=0;
14       for(int i=0;i<m;i++){
15            int x=buildings[i][0];
16            int y=buildings[i][1];
17            if(*mp_x[x].begin()==y||*mp_y[y].begin()==x){
18                continue;
19            }
20            if(*mp_x[x].rbegin()==y||*mp_y[y].rbegin()==x){
21                continue;
22            }
23            count++;
24       }
25       return count;
26    }
27};