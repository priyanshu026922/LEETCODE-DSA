class Solution {
public:
// int drow[4]={-1,0,1,0};
// int dcol[4]={0,-1,0,1};
void markVis(vector<vector<int>>&grid,int r,int c,int m,int n){
     
     for(int i=r-1;i>=0;i--){
        if(grid[i][c]==2||grid[i][c]==3)break;
        grid[i][c]=1;
     }
     for(int i=r+1;i<m;i++){
        if(grid[i][c]==2||grid[i][c]==3)break;
        grid[i][c]=1;
     }
     for(int j=c-1;j>=0;j--){
         if(grid[r][j]==2||grid[r][j]==3)break;
        grid[r][j]=1;
     }
      for(int j=c+1;j<n;j++){
         if(grid[r][j]==2||grid[r][j]==3)break;
        grid[r][j]=1;
     }
}
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
       vector<vector<int>>vec(m,vector<int>(n,0));
      
       for(auto it:guards){
            vec[it[0]][it[1]]=2;
        }
        for(auto it:walls){
            vec[it[0]][it[1]]=3;//walls
        }

      
        int ans=0;       
        for(int i=0;i<guards.size();i++){

            int x=guards[i][0];
            int y=guards[i][1];
            markVis(vec,x,y,m,n);
        }
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vec[i][j]==0)ans++;
            }
         }
         return ans;
    }
};