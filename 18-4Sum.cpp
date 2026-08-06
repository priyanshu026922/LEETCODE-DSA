class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(begin(nums),end(nums));
         set<vector<int>>s;
         for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                unordered_set<long long >s1;

                for(int k=j+1;k<n;k++){
                    long long  val=1LL*nums[i]+1LL*nums[k]+1LL*nums[j];

                    long long rem=target-val;

                    if(s1.count(rem)>0){
                        vector<int>a={nums[i],nums[j],nums[k],(int)rem};
                        sort(begin(a),end(a));
                    
                        s.insert(a);
                    }
                    s1.insert(nums[k]);
                }
            }
        }
        return  vector<vector<int>>(begin(s),end(s));
    }
};