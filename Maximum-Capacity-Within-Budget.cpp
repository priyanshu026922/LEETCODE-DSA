1class Solution {
2public:
3    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
4        int n=costs.size();
5        vector<pair<int,int>>vec(n);
6        for(int i=0;i<n;i++){
7            vec[i]={costs[i],capacity[i]};
8        }
9        sort(begin(vec),end(vec));
10        vector<int>pref(n);
11        pref[0]=vec[0].second;
12        for(int i=1;i<n;i++){
13            pref[i]=max(pref[i-1],vec[i].second);
14        }
15        int ans=0;
16        for(int i=0;i<n;i++){
17            if(vec[i].first<budget){
18                ans=max(ans,vec[i].second);
19            }
20            else{
21                break;
22            }
23            auto it=lower_bound(begin(vec),begin(vec)+i,make_pair(budget-vec[i].first,INT_MIN));
24            if(it!=begin(vec)){
25                ans=max(ans,vec[i].second+pref[it-begin(vec)-1]);
26            }
27        }
28        return ans;
29    }
30};