class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        int n=s.length();
        int maxi_freq=0;
        int maxlen=0;
        unordered_map<char,int>mp;
        while(j<n){
              mp[s[j]]++;
              maxi_freq=max(maxi_freq,mp[s[j]]);

             if((j-i+1)-maxi_freq>k){
                    mp[s[i]]--;
                    for(auto it:mp){
                        maxi_freq=max(maxi_freq,it.second);
                    }
                    i++;
               }

               if((j-i+1)-maxi_freq<=k){
                 maxlen=max(maxlen,j-i+1);
                }
                j++;
        }
        return maxlen;
    }
};