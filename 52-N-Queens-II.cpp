class Solution {
public:
    int cnt;
    bool isSafe(vector<vector<char>>&board,int i,int j,int n){
        for(int k=0;k<=j;k++){
            if(board[i][k]=='Q')return false;
        }

        int x=i;
        int y=j;
        while(x>=0&&y>=0){
            if(board[x][y]=='Q')return false;
            x--;
            y--;
        }

        x=i;
        y=j;
        while(x<n&&y>=0){
            if(board[x][y]=='Q')return false;
            x++;
            y--;
        }

        return true;
    }
    void solve(vector<vector<char>>&board,int j,int n){
        
        if(j==n){
             cnt++;
            return;
        }


        for(int k=0;k<n;k++){
            if(isSafe(board,k,j,n)){
                board[k][j]='Q';
                solve(board,j+1,n);
                board[k][j]='.';
            }
        }
    }
    int totalNQueens(int n) {
         cnt=0;
         vector<vector<char>>board(n,vector<char>(n,'.'));
         solve(board,0,n);//j,n
         return cnt;
    }
};