class Solution {
public:
typedef long long ll;
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,ll success) {
       
         int n=spells.size();
         int m=potions.size();
         sort(begin(potions),end(potions));
          vector<int>ans(n);
         for(int i=0;i<n;i++){
           ll x=spells[i];
           auto y=lower_bound(begin(potions),end(potions),(double)success/x);
          
           ans[i]=m-(y-begin(potions));
         }
         return ans;
    }
};