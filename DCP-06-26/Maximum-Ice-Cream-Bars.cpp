1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        int n=costs.size();
5        int s=0;
6        int cnt=0;
7        sort(begin(costs),end(costs));
8        for(int i=0;i<n;i++){
9            if(s+costs[i]<=coins){
10                s+=costs[i];
11                cnt++;
12            }else{
13                break;
14            }
15        }
16        return cnt;
17    }
18};