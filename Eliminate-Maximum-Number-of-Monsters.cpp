1class Solution {
2private:
3   int n;
4public:
5    bool static cmp(pair<int,int>&p1,pair<int,int>&p2){
6        double val1=(double)p1.first/(double)p1.second;
7        double val2=(double)p2.first/(double)p2.second;
8        if(val1==val2){
9            return p1.first<p2.first;
10        }
11        return val1<val2;
12    }
13    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
14         n=dist.size();
15
16         vector<pair<int,int>>vec(n);
17
18         for(int i=0;i<n;i++){
19            vec[i]={dist[i],speed[i]};
20         }
21
22         sort(begin(vec),end(vec),cmp);
23
24         int cnt=1;
25         double time=0.0;
26         for(int i=1;i<n;i++){
27
28            //  double t1=vec[i-1].first/vec[i-1].second;
29             double t2=(double)vec[i].first/(double)vec[i].second;
30            
31            //  cout<<"t1::"<<t1<<":::::"<<"t2:::"<<t2<<endl;
32             if(t2-time>1.0){
33                time+=1.0;
34                cnt++;
35                // cout<<"i::"<<i<<endl;
36             }else{
37                break;
38             }
39
40         }
41         return cnt;
42    }
43};