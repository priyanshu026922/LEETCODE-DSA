1class Solution {
2public:
3   bool isTrionic(vector<int>& nums) {
4        int n = nums.size();
5        if (n < 4) return false;
6
7        int i = 0;
8
9        // First strictly increasing
10        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
11        if (i == 0 || i == n - 1) return false;
12
13        int p = i;
14
15        // Strictly decreasing
16        while (i + 1 < n && nums[i] > nums[i + 1]) i++;
17        if (i == p || i == n - 1) return false;
18
19        int q = i;
20
21        // Strictly increasing again
22        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
23
24        return i == n - 1;
25    }
26};