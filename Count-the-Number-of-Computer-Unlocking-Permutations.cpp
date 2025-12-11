1class Solution {
2public:
3int mod=1e9+7;
4typedef long long ll;
5    int countPermutations(vector<int>& complexity) {
6        int n=complexity.size();
7        ll res=1;
8        for(int i=1;i<n;i++){
9            if(complexity[i]<=complexity[0])return 0;
10            res=(res*i)%mod;
11        }
12        return res;
13    }
14};