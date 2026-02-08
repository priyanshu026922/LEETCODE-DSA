1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        int n=strs.size();
5        int cnt=0;
6        int m=strs[0].length();
7       vector<int>cut(n-1,0);
8        for(int j=0;j<m;j++){
9            bool t=false;
10            for(int i=0;i<n-1;i++){
11                 char ch1=strs[i][j];
12                 char ch2=strs[i+1][j];
13                 if(!cut[i]&&ch1>ch2){
14                    cnt++;
15                    t=true;
16                    break;
17                 }
18            }
19            if(t)continue;
20             for (int i = 0; i < n - 1; i++) {
21                if (strs[i][j] < strs[i + 1][j]) {
22                    cut[i] = true;
23                }
24            }
25        }
26
27        return cnt;
28
29    }
30};