class Solution {
public:
    typedef long long ll;
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size();
        int m=shifts.size();
        vector<int>ans(m);

        vector<ll>pref(n,0);
        pref[0]=tasks[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+1LL*tasks[i];
        }

        ll total=pref[n-1];

        ll curr_completed=0;
        for(int i=0;i<m;i++){
            curr_completed+=1LL*shifts[i];
            if(curr_completed>=total){
                ans[i]=0;
                curr_completed=0;
            }else{
                int ind=upper_bound(begin(pref),end(pref),curr_completed)-pref.begin();
                ans[i]=n-ind;
            }
        }
        return ans;
    }
};