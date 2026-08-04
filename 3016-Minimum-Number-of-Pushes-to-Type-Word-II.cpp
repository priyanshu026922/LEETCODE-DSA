class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        vector<int>mp(26,0);
        for(auto it:word){
                mp[it-'a']++;
        }
        sort(rbegin(mp),rend(mp));
     int ans=0;
     for(int i=0;i<26 &&mp[i]>0;i++){
          ans+=mp[i]*(i/8+1);
     }
     return ans;

    }
};