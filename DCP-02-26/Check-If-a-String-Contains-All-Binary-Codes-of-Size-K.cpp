1class Solution {
2public:
3    bool hasAllCodes(string s, int k) {
4        int n=s.length();
5        unordered_set<string>st;
6        for(int i=0;i<=n-k;i++){
7            string x=s.substr(i,k);
8            st.insert(x);
9        }
10        if(st.size()==(1<<k)){
11            return true;
12        }
13        return false;
14    }
15};