class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
       unordered_map<char,int>mp;
       for(auto it:word){
        mp[it]++;
       }
       vector<int>vec;
        for(auto &it:mp){
            char ch=it.first;
            int cnt=it.second;
            vec.push_back(cnt);
           

        }

        int m=vec.size();
        sort(rbegin(vec),rend(vec));

        vector<int>pref_sum(m,0);
        pref_sum[0]=vec[0];

        for(int i=1;i<m;i++){
            pref_sum[i]=pref_sum[i-1]+vec[i];
        }
       //pref_sum bna liye
         
        //  for(auto &it:pref_sum){
        //     cout<<it<<" ";
        //  }
        //  cout<<endl;
        int ind=0;
        int ans=0;
        int last=-1;
        int type=1;
        while(ind<m){
            int i=min(ind+7,m-1);

            ans=ans+(pref_sum[i]-(last>=0?pref_sum[last]:0))*type;
            // cout<<"ans::"<<ans<<endl;
            last=i;
            type++;

            ind=i+1;
        }
        return ans;

    }
};