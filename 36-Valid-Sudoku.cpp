class Solution {
public:
  bool isValid(vector<vector<char>>& board,int i,int j,char ch){
        for(int k=0;k<9;k++){
            if(board[i][k]==ch&&k!=j)return false;
            if(board[k][j]==ch&&i!=k)return false;
            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==ch&&(3*(i/3)+k/3)!=i&&(3*(j/3)+k%3)!=j)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    //can we put any number here
                        if(!isValid(board,i,j,board[i][j])){
                            return false;
                        }
                }
                   
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return  solve(board);
    }
};