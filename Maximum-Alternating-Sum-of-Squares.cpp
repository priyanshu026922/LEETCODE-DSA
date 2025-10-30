class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
            int n=nums.size();
    vector<int>v(n);
     for(int i=0;i<n;i++){
         v[i]=abs(nums[i]);
     }
     int i;
    sort(rbegin(v),rend(v));
        long long a1=0;
        long long a2=0;
if(n&1){
    for(i=0;i<n/2+1;i++){
        a1+=v[i]*v[i];
    }
    for(;i<n;i++){
        a1-=v[i]*v[i];
    }
    return a1;
}else{
     for(i=0;i<n/2;i++){
        a2+=v[i]*v[i];
    }
     for(;i<n;i++){
        a2-=v[i]*v[i];
    }
    return a2;
}
        return 0;
    }
};