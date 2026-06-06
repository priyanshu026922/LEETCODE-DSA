1class Solution {
2public:
3    int merge(int l,int mid,int r,vector<int>&nums){
4        int i=l;
5        int j=mid+1;
6        vector<int>temp;
7        int cnt=0;
8 
9       int p=mid+1;
10       for(int x=l;x<=mid;x++){
11          while(p<=r&&1LL*nums[x]>2LL*nums[p]){
12            p++;
13          }
14          cnt+=(p-(mid+1));
15       }
16
17        while(i<=mid&&j<=r){
18            if(nums[i]<nums[j]){
19                 temp.push_back(nums[i]);
20                 i++;
21            }else{
22                temp.push_back(nums[j]);
23                j++;
24            }
25        }
26        
27        while(i<=mid){
28            temp.push_back(nums[i]);
29            i++;
30        }
31        while(j<=r){
32            temp.push_back(nums[j]);
33            j++;
34        }
35
36        for(int k=l;k<=r;k++){
37            nums[k]=temp[k-l];
38        }
39
40       return cnt;
41    }
42
43    void solve(vector<int>&nums,int l,int r,int &cnt){
44        if(l==r)return;
45        int mid=(l+r)/2;
46
47        solve(nums,l,mid,cnt);
48        solve(nums,mid+1,r,cnt);
49        cnt+=merge(l,mid,r,nums);
50    }
51    int reversePairs(vector<int>& nums) {
52        // reverse(begin(nums),end(nums));
53
54        int n=nums.size();
55        int cnt=0;
56        solve(nums,0,n-1,cnt);
57        return cnt;
58    }
59};