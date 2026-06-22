1class Solution {
2public:
3    int chalkReplacer(vector<int>& chalk, int k) {
4        int n=chalk.size();
5        long long  sum=accumulate(begin(chalk),end(chalk),0LL);
6
7        k%=sum;
8        for(int i=0;i<n;i++){
9            if(k-1LL*chalk[i]>=0){
10                k-=(1LL*chalk[i]);
11            }else{
12                return i;
13            }
14        }
15        return 0;
16    }
17};