1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        int n=s.length();
5        if(n==0){
6            return 0;
7        }
8        int j=0;
9        int i=0;
10        int maxi=INT_MIN;
11        
12        unordered_map<char,int>mp;
13        while(j<n){
14            mp[s[j]]++;
15
16            while(mp.find(s[i])!=mp.end()&&mp[s[j]]>1){
17                mp[s[i]]--;
18                if(mp[s[i]]==0){
19                    mp.erase(s[i]);
20                }
21                 
22                i++;
23            }
24             
25            maxi=max(maxi,j-i+1);
26            // cout<<"j::"<<j<<":::"<<i<<"::::"<<maxi<<endl;
27            j++;
28        }
29        return maxi;
30    }
31};