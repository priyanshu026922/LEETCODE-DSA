class Solution {
public:

 bool static cmp(vector<int>&point1,vector<int>&point2){
    if(point1[0]==point2[0]){
        return point1[1]>point2[1];
    }
    return point1[0]<point2[0];
 }

    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        int count=0;

        sort(begin(points),end(points),cmp);

        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            int maxY=INT_MIN;
            for(int j=i+1;j<n;j++){
                int x2=points[j][0];
                int y2=points[j][1];

            if(y2>y1){
                continue;
            }
            
            if(y2>maxY){
                count++;
                maxY=y2;
            }
               
            }
        }
            return count;

    }
};