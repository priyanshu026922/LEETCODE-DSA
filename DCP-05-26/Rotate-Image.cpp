1class Solution {
2public:
3// 90 = transpose + reverse row
4// 180 = reverse row + reverse column
5// 270 = transpose + reverse col
6    void rotate(vector<vector<int>>& matrix) {
7        int n=matrix.size();
8
9           for(int i=0;i<n;i++){
10            for(int j=i+1;j<n;j++){
11               swap(matrix[j][i],matrix[i][j]);
12            }
13        }
14
15        for(int i=0;i<n;i++){
16            reverse(begin(matrix[i]),end(matrix[i]));
17        }
18
19    }
20};