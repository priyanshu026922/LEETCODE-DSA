class Solution {
public:
int drow[4]={-1,0,1,0};
int dcol[4]={0,-1,0,1};
typedef pair<int,pair<int,int>>  P;
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int t=0;
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>>vis(n,vector<int>(m,0));
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int t=it.first;
            int i=it.second.first;
            int j=it.second.second;
            if(vis[i][j])continue;
           if(i==n-1&&j==m-1)return t;
           vis[i][j]=1;
           for(int k=0;k<4;k++){
            int i_=i+drow[k];
            int j_=j+dcol[k];
            if(i_>=0&&i_<n&&j_>=0&&j_<m&&!vis[i_][j_]&&grid[i_][j_]<=t){
                pq.push({t,{i_,j_}});
            }else if(i_>=0&&i_<n&&j_>=0&&j_<m&&!vis[i_][j_]&&grid[i_][j_]>t){
                pq.push({grid[i_][j_],{i_,j_}});
            }
           }

        }
        return -1;
    }
};