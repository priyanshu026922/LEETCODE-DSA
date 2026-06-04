1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4        int fast=nums[0];
5        int slow=nums[0];
6        while(true){
7            slow=nums[slow];
8            fast=nums[nums[fast]];
9
10            if(slow==fast){
11                break;
12            }
13        }
14
15        slow=nums[0];
16        while(slow!=fast){
17            slow=nums[slow];
18            fast=nums[fast];
19        }
20        return slow;
21    }
22};