1class Solution {
2public:
3    int bitwiseComplement(int n) {
4        if(n==0)return 1;
5        int q=32-__builtin_clz(n);
6        for(int i=0;i<q;i++){
7            if(n&(1<<i)){
8                n=(n^(1<<i));
9            }else{
10               n=(n|(1<<i));
11            }
12            cout<<n<<endl;
13        }
14        return n;
15    }
16};