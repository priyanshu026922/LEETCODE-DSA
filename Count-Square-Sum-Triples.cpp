1class Solution {
2public:
3    int countTriples(int n) {
4        int count=0;
5        for(int a=1;a<=n;a++){
6            for(int b=1;b<=n;b++){
7                int sum=a*a+b*b;
8                int c=sqrt(sum);
9
10                if(c>=1&&c<=n&&c*c==sum){
11                    count++;
12                }
13            }
14        }
15        return count;
16    }
17};