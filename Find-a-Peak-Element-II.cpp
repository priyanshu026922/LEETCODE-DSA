1class Solution {
2public:
3   int n,m;
4    int getMax(vector<vector<int>>& mat,int j){
5        int maxi=-1;
6        int ind=-1;
7        for(int i=0;i<n;i++){
8            if(mat[i][j]>maxi){
9                maxi=mat[i][j];
10                ind=i;
11            }
12        }
13        return ind;
14    }
15    vector<int> findPeakGrid(vector<vector<int>>& mat) {
16       n=mat.size();
17       m=mat[0].size();
18
19      int l=0;
20      int r=m-1;
21      while(l<=r){
22        int mid=l+(r-l)/2;
23
24        int ind=getMax(mat,mid);
25        int val1=mid-1>=0?mat[ind][mid-1]:-1;
26        int val2=mid+1<m?mat[ind][mid+1]:-1;
27        if(mat[ind][mid]>val1&&mat[ind][mid]>val2){
28            return {ind,mid};
29        }
30        else if(mat[ind][mid]<val1){
31            r=mid-1;
32        }else{
33            l=mid+1;
34        }
35      }
36      return {-1,-1};
37
38    }
39};