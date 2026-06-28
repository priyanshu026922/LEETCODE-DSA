1class Solution {
2public:
3    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
4        int n=arr.size();
5        sort(begin(arr),end(arr));
6        arr[0]=1;
7        for(int i=1;i<n;i++){
8           if(abs(arr[i]-arr[i-1])<=1){
9              continue;
10           }else{
11            arr[i]=arr[i-1]+1;
12           }
13        }
14
15        int maxi=arr[0];
16        for(int i=1;i<n;i++)maxi=max(maxi,arr[i]);
17        return maxi;
18    }
19};