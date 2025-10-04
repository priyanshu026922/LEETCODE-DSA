class Solution {
public:
int drow[4]={-1,0,1,0};
int dcol[4]={0,-1,0,1};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();

        priority_queue<pair<int,pair<int,int>>,vector< pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    
     vector<vector<bool>>vis(n,vector<bool>(m,false));

     for(int r=0;r<n;r++){
        for(int c:{0,m-1}){
            pq.push({heightMap[r][c],{r,c}});
            vis[r][c]=true;
        }
     }
     for(int c=0;c<m;c++){
        for(int r:{0,n-1}){
            pq.push({heightMap[r][c],{r,c}});
            vis[r][c]=true;
        }
     }
     int water=0;
     while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        int h=p.first;
        int i=p.second.first;
        int j=p.second.second;

        for(int x=0;x<4;x++){
            int i_=i+drow[x];
            int j_=j+dcol[x];

            if(i_>=0&&i_<n&&j_>=0&&j_<m&&!vis[i_][j_]){
                if(h-heightMap[i_][j_]>0){
                         water+=(h-heightMap[i_][j_]);
                }
                //  water+=max((h-heightMap[i_][j_]),0);
                pq.push({max(h,heightMap[i_][j_]),{i_,j_}});
                vis[i_][j_]=true;
            }
        }
     }
      return water;
    }
};