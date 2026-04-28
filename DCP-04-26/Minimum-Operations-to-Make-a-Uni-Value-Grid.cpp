1class Solution {
2public:
3    int minOperations(vector<vector<int>>& grid, int x) {
4        vector<int> values;
5        for (const auto& row : grid) {
6            for (int val : row) {
7                values.push_back(val);
8            }
9        }
10
11        sort(values.begin(), values.end());
12
13        for (int val : values) {
14            if (abs(val - values[0]) % x != 0) {
15                return -1;
16            }
17        }
18
19        int median = values[values.size() / 2];
20        int operations = 0;
21
22        for (int val : values) {
23            operations += abs(val - median) / x;
24        }
25
26        return operations;
27    }
28};