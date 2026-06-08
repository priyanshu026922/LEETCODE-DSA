1class Solution {
2public:
3 typedef pair<int,int> p;
4    vector<int> arrayRankTransform(vector<int>& arr) {
5        int N=arr.size();
6                vector<int>ans(N);
7        
8        priority_queue<p,vector<p>,greater<p>>pq;
9        
10        for(int i=0;i<N;i++){
11            pq.push({arr[i],i});
12        }
13        
14        int rank=0;
15        int last=INT_MIN;
16        while(!pq.empty()){
17            
18            int val=pq.top().first;
19            int ind=pq.top().second;
20            
21            pq.pop();
22            if(last==INT_MIN||val!=last){
23                rank++;
24            }
25            last=val;
26            ans[ind]=rank;
27        }
28        return ans;
29        
30    }
31};