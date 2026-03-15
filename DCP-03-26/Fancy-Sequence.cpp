1class Fancy {
2public:
3    typedef long long ll;
4
5    ll M = 1e9+7;
6
7    vector<ll> seq;
8    ll add = 0;
9    ll mult = 1;
10
11    //Binary Exponentiation for Fermat's Little Theorem -> power(mult, M-2);
12    long long power(long long a, long long b) {
13        if(b == 0)
14            return 1;
15
16        long long half   = power(a, b/2);
17        long long result = (half * half) % M;
18
19        if(b%2 == 1) {
20            result = (result * a) % M;
21        }
22
23        return result;
24    }
25
26    Fancy() {
27        
28    }
29    
30    void append(int val) {
31        long long x = ((val - add) % M + M) * power(mult, M-2)%M;
32        seq.push_back(x);
33    }
34    
35    void addAll(int inc) {
36        add = (add + inc) % M;
37    }
38    
39    void multAll(int m) {
40        mult = (mult * m) % M;
41        add  = (add * m) % M;
42    }
43    
44    int getIndex(int idx) {
45        if(idx >= seq.size())
46            return -1;
47
48        return (seq[idx]*mult + add) % M;
49    }
50};
51
52
53