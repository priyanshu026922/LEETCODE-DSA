class Solution {
public:
void markVis(vector<vector<int>>&grid,int r,int c,int m,int n,string dir){
     if(r<0||r>=m||c<0||c>=n)return;
             
     if(grid[r][c]==2||grid[r][c]==3)return;
     grid[r][c]=1;
    if(dir=="u") markVis(grid,r-1,c,m,n,"u");
    if(dir=="d")  markVis(grid,r+1,c,m,n,"d");
     if(dir=="r")   markVis(grid,r,c+1,m,n,"r");
     if(dir=="l")markVis(grid,r,c-1,m,n,"l");
}

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>vec(m,vector<int>(n,0));
        
            for(auto it:guards){
                vec[it[0]][it[1]]=2;
            }

            for(auto it:walls){
                vec[it[0]][it[1]]=3;
            }

                int ans=0;       
                for(int i=0;i<guards.size();i++){

                    int x=guards[i][0];
                    int y=guards[i][1];
                    markVis(vec,x-1,y,m,n,"u");
                     markVis(vec,x+1,y,m,n,"d");
                      markVis(vec,x,y+1,m,n,"r"); 
                      markVis(vec,x,y-1,m,n,"l");
                }

                
                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                        if(vec[i][j]==0)ans++;
                    }
                }
         return ans;
    }
};