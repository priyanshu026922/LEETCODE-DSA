class Solution {
public:
    bool checkPartitioning(string s) {
        int n=s.length();
        vector<vector<int>>pal(n+1,vector<int>(n+1,0));
        for(int len=1;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=len+i-1;

                if(s[i]==s[j]){
                    if(len<=2){
                        pal[i][j]=1;
                    }else{
                        pal[i][j]=pal[i+1][j-1];
                    }
                }
            }
        }
 
        for(int i=0;i<n;i++){

            for(int j=n-1;j>i+1;j--){

                if(pal[0][i]&&pal[i+1][j-1]&&pal[j][n-1]){
                    return true;
                }
                
            }
        }

        return false;
    }
};