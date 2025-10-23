class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int>diff(n,0);
        for(int i=0;i<m;i++){

             int l=queries[i][0];
             int r=queries[i][1];
             diff[l]++;
             if(r+1<n)diff[r+1]--;
        }

          vector<int>v(n,0);// shows number of operations required for each indices
          v[0]=diff[0];
        for(int i=1;i<n;i++){
            v[i]=v[i-1]+diff[i];
        }
        for(int i=0;i<n;i++){
          if(v[i]<nums[i])return false;
        }
        return true;
    }
};