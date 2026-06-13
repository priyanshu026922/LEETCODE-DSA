1class Solution {
2public:
3    string mapWordWeights(vector<string>& words, vector<int>& weights) {
4        unordered_map<char,int>mp;
5        for(int i=0;i<26;i++){
6            mp[i+'a']=weights[i];
7        }
8        
9        string ans="";
10        for(auto &it:words){
11            int sum=0;
12            for(char ch:it){
13               sum+=mp[ch];
14            }
15
16            sum=sum%26;
17           ans+=((25-sum)+'a');
18        }
19        return ans;
20    }
21};