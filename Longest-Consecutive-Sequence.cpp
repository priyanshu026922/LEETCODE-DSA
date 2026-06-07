1class Solution {
2public:
3    int longestConsecutive(vector<int>& nums) {
4       set<int>s(begin(nums),end(nums));
5       int maxi=0;
6       for(auto &it:s){
7        if(s.find(it-1)==s.end()){
8            int x=it;
9            int cnt=1;
10            while(s.find(x+1)!=s.end()){
11                x++;
12                cnt++;
13            }
14            maxi=max(maxi,cnt);
15        }
16       }
17
18        return maxi;
19       }
20};