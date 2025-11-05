class Solution {
public:
int findSum(unordered_map<int,int>&mp,int x){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(auto it:mp){
        pq.push({it.second,it.first});
        if(pq.size()>x){
            pq.pop();
        }
    }
   long long sum=0;
    while(!pq.empty()){
        int t=pq.top().first;
        int y=pq.top().second;
        pq.pop();
        sum+=(1LL*t*y);
    }
    return (int)sum;
}
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>a;
        int i=0;
        int j=0;
        int sum=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        while(j<n){
            mp[nums[j]]++;
            if(j-i+1==k){
                int t=findSum(mp,x);
                a.push_back(t);
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
           }
           j++;
        }

        return a;
    }
};