1class Solution {
2private:
3   int n;
4public:
5    // bool static cmp(pair<int,int>&p1,pair<int,int>&p2){
6    //     double val1=(double)p1.first/(double)p1.second;
7    //     double val2=(double)p2.first/(double)p2.second;
8    //     if(val1==val2){
9    //         return p1.first<p2.first;
10    //     }
11    //     return val1<val2;
12    // }
13
14    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
15         n=dist.size();
16
17         vector<double>time(n);
18
19         for(int i=0;i<n;i++){
20          time[i]=(double)dist[i]/(double)speed[i];
21         }
22
23        sort(begin(time),end(time));
24
25         int cnt=1;
26         double t=0.0;
27         for(int i=1;i<n;i++){
28
29            //  double t1=vec[i-1].first/vec[i-1].second;
30             double t2=time[i];
31            
32            //  cout<<"t1::"<<t1<<":::::"<<"t2:::"<<t2<<endl;
33             if(t2-t>1.0){
34                t+=1.0;
35                cnt++;
36                // cout<<"i::"<<i<<endl;
37             }else{
38                break;
39             }
40
41         }
42         return cnt;
43    }
44};