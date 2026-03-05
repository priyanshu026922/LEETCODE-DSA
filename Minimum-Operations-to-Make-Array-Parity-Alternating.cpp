1class Solution {
2public:
3int n;
4    int solve(vector<int>&nums,int parity){//p==0
5        int mini=INT_MAX;
6        int maxi=INT_MIN;
7        for(int i=0;i<n;i++){
8            int val1=nums[i]-1;
9            int val2=nums[i]+1;
10            if((nums[i]%2==0&&!parity)||(nums[i]%2!=0&&parity)){
11                mini=min(mini,val2);
12                maxi=max(maxi,val1);
13            }else{
14                mini=min(mini,nums[i]);
15                maxi=max(maxi,nums[i]);
16            }
17            parity=!parity;
18        }
19        return maxi-mini;
20    }
21
22    vector<int> makeParityAlternating(vector<int>& nums) {
23        n=nums.size();
24        
25        if(n==1){
26            return {0,0};
27        }
28        unordered_set<int>s(begin(nums),end(nums));
29        if(s.size()==1){
30            return {n/2,1};
31        }
32
33        int e_o=0;//010101...
34        for(int i=0;i<n;i++){
35            if(i%2==0){
36                if(nums[i]%2==0)continue;
37                else e_o++;
38            }else{
39                 if(nums[i]%2!=0)continue;
40                else e_o++;
41            }
42        }
43
44        int o_e=n-e_o;
45        //parity--->0--->e_o//010101....
46        //parity-->1--->o_e//1010101....
47        if(e_o==o_e){
48            int x=min(solve(nums,1),solve(nums,0));
49            return {e_o,x};
50        }
51
52        if(e_o>o_e){
53           return {o_e,solve(nums,0)};
54        }
55
56        return {e_o,solve(nums,1)};
57    }
58};