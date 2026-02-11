1class Solution {
2public:
3    struct SegTree {
4        int n;
5        vector<int> sum, mn, mx;
6        vector<int>  lazyVal;
7        vector<bool> hasLazy;
8
9        SegTree(int _n){
10            n = _n;
11            sum.assign(4 * n + 5, 0);
12            mn.assign(4 * n + 5, 0);
13            mx.assign(4 * n + 5, 0);
14            lazyVal.assign(4 * n + 5, 0);
15            hasLazy.assign(4 * n + 5, 0);
16            
17        }
18
19        void pull(int v){
20            sum[v] = sum[v << 1] + sum[v << 1 | 1];
21            mn[v] = min(mn[v << 1], sum[v << 1] + mn[v << 1 | 1]);
22            mx[v] = max(mx[v << 1], sum[v << 1] + mx[v << 1 | 1]);
23        }
24
25        void applySet(int v, int l, int r, int val){
26            int len = r - l + 1;
27            sum[v] = 1LL * val * len;
28
29            if(val == 0){
30                mn[v] = 0;
31                mx[v] = 0;
32            }
33            else if(val > 0){
34                mn[v] = val;
35                mx[v] = 1LL * val * len;
36            }
37            else{
38                mn[v] = 1LL * val * len;
39                mx[v] = val;
40            }
41
42            hasLazy[v] = true;
43            lazyVal[v] = val;
44        }
45
46        void push(int v, int l, int r){
47            if(!hasLazy[v] || l == r) return;
48            int m = (l + r) >> 1;
49            applySet(v << 1, l, m, lazyVal[v]);
50            applySet(v << 1 | 1, m + 1, r, lazyVal[v]);
51            hasLazy[v] = false;
52        }
53
54
55        void update(int pos, int newval){
56            update(1, 0, n - 1, pos, pos, newval);
57        }
58
59        void update(int v, int l, int r, int ql, int qr, int val){
60            if(ql <= l && r <= qr){
61                applySet(v, l, r, val);
62                return;
63            }
64            push(v, l, r);
65            int m = (l + r) >> 1;
66            if(ql <= m) update(v << 1, l, m, ql, qr, val);
67            if(qr >  m) update(v << 1 | 1, m + 1, r, ql, qr, val);
68            pull(v);
69        }
70
71        int query(int x){
72            if(x == 0) return -1;
73            if(x < mn[1] || x > mx[1]) return n;
74            int pref = 0;
75            return query(1, 0, n - 1, x, pref);
76        }
77
78        int query(int v, int l, int r, int x, int& pref){
79            if(l == r){
80                if(pref + sum[v] == x) return l;
81                return n;
82            }
83
84            push(v, l, r);
85
86            int m = (l + r) >> 1;
87            int L = v << 1;
88            int R = v << 1 | 1;
89
90            int leftMin = pref + mn[L];
91            int leftMax = pref + mx[L];
92
93            if(x >= leftMin && x <= leftMax){
94                return query(L, l, m, x, pref);
95            }
96            else{
97                pref += sum[L];
98                return query(R, m + 1, r, x, pref);
99            }
100        }
101    };
102
103    int longestBalanced(vector<int>& nums) {
104        int n = (int)nums.size();
105        int m = 0;
106        for(auto x : nums) m = max(m, x);
107        m += 1;
108
109        vector<int> lastPos(m, -1);
110        SegTree S(n);
111
112        int sum = 0;
113        int ans = 0;
114
115        for(int i = 0; i < n; i ++){
116            if(lastPos[nums[i]] != -1){
117                S.update(lastPos[nums[i]], 0);
118            }
119            else{
120                if(nums[i] % 2){
121                    sum += 1;
122                }
123                else{
124                    sum -= 1;
125                }
126            }
127
128            lastPos[nums[i]] = i;
129
130            if(nums[i] % 2){
131                S.update(i, +1);
132            }
133            else{
134                S.update(i, -1);
135            }
136
137            int p = S.query(sum);
138            ans = max(ans, i - p);
139        }
140
141        return ans;
142    }
143};