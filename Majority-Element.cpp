1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        int n=nums.size();
5
6        //MOORE-VOTING ALGORITHM
7
8        int ele=-1;
9        int cnt=0;
10        for(int i=0;i<n;i++){
11            if(cnt==0){
12              ele=nums[i];
13              cnt++;
14            }
15            else if(ele==nums[i]){
16               cnt++;
17            }else{
18                cnt--;
19            }
20        }
21
22        return ele;
23
24        
25    }
26};