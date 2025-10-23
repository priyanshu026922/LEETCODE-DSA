class Solution {
public:
int m,n;
    bool allZero(vector<int>& nums){
        for(int i=0;i<m;i++){
            if(nums[i]!=0)return false;
        }
        return true;
    }

    bool checkWithDiffArray(vector<int>& nums, vector<vector<int>>& queries,int x){
        vector<int>diff(m,0);
        for(int i=0;i<=x;i++){
           int l=queries[i][0];
           int r=queries[i][1];
           int val=queries[i][2];
           diff[l]+=val;
                if(r+1<m){
                    diff[r+1]-=val;
                }
        }

          vector<int>vec(m,0);
          vec[0]=diff[0];
        for(int i=1;i<m;i++){
            vec[i]=vec[i-1]+diff[i];
        }


        for(int i=0;i<m;i++){
            if(vec[i]<nums[i]){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n= queries.size();
        m=nums.size();

        if(allZero(nums)){
            return 0;
        }


         int l=0;
         int h=n-1;
         int ans=-1;
         while(l<=h){
           int mid=l+(h-l)/2;
            if(checkWithDiffArray(nums,queries,mid)){
                ans=mid+1;
                h=mid-1;
            }else{
                l=mid+1;
            }
         }
        // for(int i=0;i<n;i++){
        //     if(checkWithDiffArray(nums,queries,i)){
        //         return i+1;
        //     }
        // }

        return ans;


        
        
   }
};