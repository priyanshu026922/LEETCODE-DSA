class Solution {
public:

// static bool cmp(const vector<int>&a,const vector<int>&b){
//       if (a[0]==b[0])return a[1]<b[1];
//       return a[0]<b[0];
// }

int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int day=events[0][0];
        int i=0;
        int count=0;
        
        while(!pq.empty()||i<n){
            if(pq.empty())day=events[i][0];
            while(i<n&&events[i][0]==day){
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty()){
                pq.pop();
            count++;
            }
            day++;


            while(!pq.empty()&&pq.top()<day){
                pq.pop();
            }

        }
        // for(int i=1;i<n;i++){
        //         int x=events[i][0];
        //         int y=events[i][1];
        //         if(val-1<=y){
        //             val;
        //             count++;
        //             s.insert(val);
        //         }else{
        //             val=x;
        //             if(!s.count(val))count++;
        //         }
        // }
        // for(auto it:events){
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }
    return count;
  }
};