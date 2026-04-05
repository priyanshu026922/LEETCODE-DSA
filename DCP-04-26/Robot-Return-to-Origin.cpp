1class Solution {
2public:
3    bool judgeCircle(string moves) {
4        int n=moves.length();
5        int up=0;
6        int l=0;
7        for(int i=0;i<n;i++){
8            if(moves[i]=='U'){
9                up++;
10            }else if(moves[i]=='L'){
11                l++;
12            }else if(moves[i]=='R'){
13                l--;
14            }else{
15                up--;
16            }
17        }
18        return (up==0)&&(l==0);
19    }
20};