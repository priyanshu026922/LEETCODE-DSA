1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        int count=0;
5        int n=strs.size();
6        int m=strs[0].length();
7        for(int i=0;i<m;i++){
8             char ch=strs[0][i];
9            for(int j=1;j<n;j++){
10                string s=strs[j];
11                char ch1=s[i];
12                if(ch<=ch1){
13                   ch=ch1;
14                }else{
15                    count++;
16                    break;
17                }
18            }
19        }
20        return count;
21    }
22};