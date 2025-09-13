class Solution {
public:
int drow[4]={-1,0,1,0};
int dcol[4]={0,-1,0,1};
    int minimumEffortPath(vector<vector<int>>& heights) { 
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>shorter(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int d=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
           if(i==n-1&&j==m-1)return d;
           for(int t=0;t<4;t++){
            int x=drow[t]+i;
            int y=dcol[t]+j;
            if(x>=0&&x<n&&y>=0&&y<m){
                int newDiff=max(abs(heights[i][j]-heights[x][y]),d);
                if(newDiff<shorter[x][y]){
                    shorter[x][y]=newDiff;
                    pq.push({newDiff,{x,y}});
                }
            }
           }
        }
        return -1;
    }
};