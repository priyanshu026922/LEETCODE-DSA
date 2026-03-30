1class Solution {
2public:
3    bool checkStrings(string s1, string s2) {
4        int n=s1.length();
5       vector<int>e(26,0);
6       vector<int>o(26,0);
7
8        for(int i=0;i<n;i++){
9            if(i%2==0){
10                e[s1[i]-'a']++;
11                e[s2[i]-'a']--;
12            }else{
13                o[s1[i]-'a']++;
14                o[s2[i]-'a']--;
15            }
16        }
17
18        for(int i=0;i<26;i++){
19           if(e[i]!=0||o[i]!=0)return false;
20        }
21
22        return true;
23    }
24};