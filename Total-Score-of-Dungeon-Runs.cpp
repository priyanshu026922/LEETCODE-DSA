1class Solution {
2public:
3    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
4            int n=damage.size();
5            vector<long long>a(n+1);
6            // a[1]=damage[0];
7            for(int i=1;i<=n;i++){
8                a[i]=a[i-1]+damage[i-1];
9            }
10            long long ans=0;
11            for(int j=1;j<=n;j++){
12                long long tar=requirement[j-1]+a[j]-hp;
13                auto it=lower_bound(begin(a),end(a),tar);
14                int ind=it-begin(a);
15                if(ind+1>j){
16                    continue;
17                }
18                ind++;
19                ans+=(j-ind+1);
20            }
21             return ans;
22    }
23};