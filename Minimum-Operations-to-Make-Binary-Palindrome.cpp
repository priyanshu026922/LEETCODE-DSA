1class Solution {
2public:
3  string toBinary(int x) {
4        string s = "";
5        while (x) {
6            s += (x % 2) + '0';
7            x /= 2;
8        }
9        return s;
10    }
11bool isPalindrome(string s){
12    int n=s.length();
13    int i=0;
14    int j=n-1;
15    while(i<=j){
16        if(s[i]!=s[j])return false;
17        i++;
18        j--;
19    }
20    return true;
21}
22    vector<int> minOperations(vector<int>& nums) {
23         vector<int>a;
24         for(int i=1;i<=5000;i++){
25            string q=toBinary(i);
26            if(isPalindrome(q)){
27                a.push_back(i);
28            }
29         }
30         
31         int n=nums.size();
32         vector<int>ans(n,0);
33         for(int i=0;i<n;i++){
34            if(nums[i]==1){
35                ans[i]=0;
36                continue;
37            }
38            auto lb =lower_bound(begin(a),end(a),nums[i]);
39            int y=lb-begin(a);
40            int z=y-1;
41            int mini=min(abs(nums[i]-a[z]),abs(nums[i]-a[y]));
42             ans[i]=mini;
43         }
44         return ans;
45    }
46};