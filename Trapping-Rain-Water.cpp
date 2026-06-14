1class Solution {
2public:
3    int trap(vector<int>& height) {
4        int n=height.size();
5        //heights= [0,1,0,2,1,0,1,3,2,1,2,2];
6        //trying out by 2pointer mehtod
7        //in that ,method we were doing somehting maxi from left,max from right side
8         
9         //in the brute force method ,at one step we wwere doing somehting like min(left[i],right[i]);
10       //l=1
11       //r=n-1;
12
13       //if(height[l]<=height[r]){
14           //minimu for sure would be on the left side..but not neccessaryily be that nums[l]
15          //if(height[l]>maxiL){
16            //total+=(height[l]-height[l])===0;
17              //maxiL=height[l]
18            //}else{
19                //
20                //total+=(maxiL-height[l]);
21            //}
22
23       //}else{
24
25
26
27       //}
28       int total=0;
29        int maxiL=0;
30        int maxiR=0;
31       int l=0;
32       int r=n-1;
33       while(l<=r){
34         if(height[l]<=height[r]){
35                if(maxiL>=height[l]){
36                    total+=(maxiL-height[l]);
37                }else{
38                    maxiL=height[l];
39                }
40
41                l++;
42         }else{
43               if(maxiR>=height[r]){
44                    total+=(maxiR-height[r]);
45                }else{
46                    maxiR=height[r];
47                }
48
49                r--;
50         }
51
52
53       }
54       return  total;
55
56
57       
58    }
59};