class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        int n=intervals.size();
        int cnt=0;
        int s=intervals[0][0];
        int e=intervals[0][1];

        for(int i=1;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];

            if(start==s){
                if(e<=end){
                   cnt++;
                }

                e=end;
            }else{//start<s
                
                if(end<=e){
                    cnt++;
                }else{
                   s=start;
                   e=end;
                }
            }
        }
        return n-cnt;

        //ans===>n-x--->x:no of merged intervals

    }
};