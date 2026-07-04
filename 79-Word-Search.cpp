class Solution {
private:
   int n,m,N;
public:
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,-1,0,1};
    int dp[7][8];
    bool solve(vector<vector<char>>& board,int i,int j,string s, string word,  int idx){
        
       if(i<0||j<0||i>=n||j>=m){
          return false;
       }
        
       
       if(board[i][j]!=word[idx]){
          return false;;
       }

       if(idx==word.length()-1){
            return true;
       }

    
       s+=board[i][j];
       board[i][j]='#';
      
       for(int k=0;k<4;k++){
         int new_i=drow[k]+i;
         int new_j=dcol[k]+j;
            
            
            if(new_i<0||new_j<0||new_i>=n||new_j>=m){
                continue;
            }
           
            if(board[new_i][new_j]!='#'){
                if(solve(board,new_i,new_j,s,word,idx+1)){
                    return true;
                }
            }


       }

       board[i][j]=word[idx];

       return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();

           for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){

                    if(solve(board,i,j,"",word,0)){
                        return true;
                    }
                }
           }
        return false;
    }
};