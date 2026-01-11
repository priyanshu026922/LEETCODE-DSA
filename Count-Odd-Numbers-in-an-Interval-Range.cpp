1class Solution {
2public:
3    int countOdds(int low, int high) {
4        long long cnt=high-low+1;
5        if(low%2&&high%2){
6            return cnt/2+1;
7        }
8        return cnt/2;
9    }
10};  