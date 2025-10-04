class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int maxArea=0;
      while(l<r){
        if(height[l]<height[r]){
             maxArea=max(maxArea,(r-l)*height[l]);
             l++;
        }else{
              maxArea=max(maxArea,(r-l)*height[r]);
             r--;
        }
      }
      return maxArea;
    }
};