class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
   int x=classes.size();
priority_queue<pair<double,int>>pq;
for(int i=0;i<x;i++){
    double passR=(double)classes[i][0]/(double)classes[i][1];
    double updated=(double)(classes[i][0]+1)/((double)classes[i][1]+1);
    double delta=updated-passR;
    pq.push({delta,i});
}
while(extraStudents--){
   auto curr=pq.top();
   pq.pop();
   double delta=curr.first;
   int idx=curr.second;
classes[idx][0]++;
classes[idx][1]++;

double passR=(double)classes[idx][0]/(double)classes[idx][1];
    double updated=(double)(classes[idx][0]+1)/((double)classes[idx][1]+1);
    delta=updated-passR;
    pq.push({delta,idx});
}
double res=0.0;
for(int i=0;i<x;i++){
res+=(double)classes[i][0]/(double)classes[i][1];
}
return res/x;
    }
};