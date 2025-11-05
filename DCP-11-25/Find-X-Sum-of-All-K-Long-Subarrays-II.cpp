class Solution {
public:
typedef long long ll;
ll sum=0;
set<pair<int,int>>main;
set<pair<int,int>>sec;
void  insertInSet(const pair<int,int>&p,int x){
    if(main.size()<x||p>*main.begin()){
        sum+=1LL*p.first*p.second;
        main.insert(p);
        if(main.size()>x){
            auto remove=*main.begin();
            sum-=1LL*remove.first*remove.second;
            main.erase(remove);
            sec.insert(remove);
        }
    }else{
        sec.insert(p);
    }
}
void removeFromSet(const pair<int,int>&p,int x){
    if(main.find(p)!=main.end()){
        sum-=1LL*p.first*p.second;
        main.erase(p);

        if(!sec.empty()){
            auto largest=*sec.rbegin();
           sec.erase(largest);
           main.insert(largest);
           sum+=1LL*largest.first*largest.second;
        }
    }else{
        sec.erase(p);
    }
}
    vector<ll> findXSum(vector<int>& nums, int k, int x) {
       vector<ll>a;
        int i=0;
        int j=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        while(j<n){

            if(mp[nums[j]]>0){
                removeFromSet({mp[nums[j]],nums[j]},x);
            }

            mp[nums[j]]++;
            insertInSet({mp[nums[j]],nums[j]},x);

            if(j-i+1==k){
                a.push_back(sum);
                removeFromSet({mp[nums[i]],nums[i]},x);
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                else   insertInSet({mp[nums[i]],nums[i]},x);
                i++;
           }
           j++;
        }

        return a;
    }
}; 