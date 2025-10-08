class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
      unordered_map<char,int>mp;
       int sum=0;
        for(int i=0;i<n;i++){
            mp.clear();
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                int maxi=INT_MIN;
            int mini=INT_MAX;
            for(auto it:mp){
                maxi=max(maxi,it.second);
                 mini=min(mini,it.second);
            }
                sum+=(maxi-mini);
            }
        }
        return sum;
    }
};