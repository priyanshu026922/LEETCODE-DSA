class Solution {
public:
    bool static cmp(pair<int,int>&p1,pair<int,int>&p2){
        int x=p1.first-p1.second;
        int y=p2.first-p2.second;
        if(x!=y){
            return x<y;
        }
        return p1<p2;
    }

    int maximumBags(vector<int>& c, vector<int>& r, int aR) {
       int  n=c.size();
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++){
            vec[i]={c[i],r[i]};
        }


        sort(begin(vec),end(vec),cmp);
        //  for(auto &it:vec){
        //     cout<<it.first<<":::"<<it.second<<endl;
        //  }
        int cnt=0;
        for(int i=0;i<n;i++){
            int x=vec[i].first-vec[i].second;
            if(x<=aR){
                // cout<<i<<"x::"<<x<<endl;
                cnt++;

                aR-=x;
            }else{
                break;
            }
        }
        return cnt;
    }
};