1class Solution {
2public:
3    vector<int> majorityElement(vector<int>& nums) {
4        int n=nums.size();
5        //at max there will be 2 elemnt having cnt>n/3
6
7       long long ele1 = LLONG_MIN, cnt1 = 0;
8       long long  ele2 = LLONG_MIN, cnt2 = 0;
9       
10        for(int i=0;i<n;i++){
11            if(cnt1==0&& ele2!=nums[i]){
12                //kyunki agar nums[i]==ele2-->toh sidhe cnt2++ kro
13                ele1=nums[i];
14                cnt1=1;
15            }
16            else if(cnt2==0&& ele1!=nums[i]){
17                //kyunki agar nums[i]==ele1-->toh sidhe cnt1++ kro
18                ele2=nums[i];
19                cnt2=1;
20            } 
21            else if(ele1==nums[i]){
22                cnt1++; 
23            }
24            else if(ele2==nums[i]){
25                cnt2++;
26            }
27            else if(ele1!=nums[i]&&ele2!=nums[i]){
28                cnt1--;
29                cnt2--;
30            }
31        }
32
33        vector<int>ans;
34        int c1=0,c2=0;
35        for(int i=0;i<n;i++){
36            if(nums[i]==ele1)c1++;
37            if(nums[i]==ele2)c2++;
38        }
39
40        if(c1>n/3)ans.push_back(ele1);
41        if(c2>n/3)ans.push_back(ele2);
42        return ans;
43    }
44};