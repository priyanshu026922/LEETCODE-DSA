class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);

            while(ans.size()>1){
                long long x1=ans.back();
                ans.pop_back();
                 long long x2=ans.back();
                ans.pop_back();
               long long x=gcd(x1,x2);
                if(x>1){
               long long l=1LL*x1/x *x2;
              ans.push_back(l);
            }
            if(x==1){
                ans.push_back(x2);
                 ans.push_back(x1);
                 break;
            } 
            }
        }
        return ans;
    }
};