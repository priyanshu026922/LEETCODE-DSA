1class Solution {
2public:
3    int leastInterval(vector<char>& tasks, int n) {
4       vector<int>mp(26,0);
5       for(int i=0;i<tasks.size();i++){
6        mp[tasks[i]-'A']++;
7       }
8
9       sort(begin(mp),end(mp));
10
11       int largest=mp[25];
12       int gaps=largest-1;
13       int freespots=(largest-1)*n;
14
15       for(int i=24;i>=0;i--){
16        freespots-=min(gaps,mp[i]);
17       }
18
19       if(freespots>0){
20        return tasks.size()+freespots;
21       }
22       return tasks.size();
23    }
24};