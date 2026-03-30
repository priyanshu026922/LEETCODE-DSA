1class Solution {
2public:
3    bool checkStrings(string s1, string s2) {
4        int n=s1.length();
5        unordered_map<char,int>e;
6        unordered_map<char,int>o;
7
8        for(int i=0;i<n;i++){
9            if(i%2==0){
10                e[s1[i]]++;
11            }else{
12                o[s1[i]]++;
13            }
14        }
15
16        for(int i=0;i<n;i++){
17            if(i%2==0){
18               if(e.find(s2[i])==e.end()){
19                return false;
20               }
21               e[s2[i]]--;
22               if(e[s2[i]]==0){
23                e.erase(s2[i]);
24               }
25            }else{
26                if(o.find(s2[i])==o.end()){
27                  return false;
28                }
29               o[s2[i]]--;
30               if(o[s2[i]]==0){
31                o.erase(s2[i]);
32               }
33            }
34        }
35        return true;
36    }
37};