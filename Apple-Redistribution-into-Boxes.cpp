1class Solution {
2public:
3    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
4        int n=capacity.size();
5        sort(rbegin(capacity),rend(capacity));
6        int sum=accumulate(begin(apple),end(apple),0);
7        int s=0;
8        for(int i=0;i<n;i++){
9            s+=capacity[i];
10            if(s>=sum){
11                return i+1;
12            }
13        }
14        return -1;
15    }
16};