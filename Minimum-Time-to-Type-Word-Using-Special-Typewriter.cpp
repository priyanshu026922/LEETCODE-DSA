1class Solution {
2public:
3    int minTimeToType(string word) {
4        int n=word.length();
5        char ch='a';
6        int ans=0;
7        for(int i=0;i<n;i++){
8              int val1=abs(word[i]-ch);
9              ans+=min(val1,26-val1);
10              ch=word[i];
11              ans++;
12        }
13        return ans;
14    }
15};