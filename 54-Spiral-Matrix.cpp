class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        
        int n=matrix.size();
        int m=matrix[0].size();

        int u=0;
        int d=n-1;


        int l=0;
        int r=m-1;


        while(u<=d&&l<=r){

            //first row
            for(int i=l;i<=r;i++){
                ans.push_back(matrix[u][i]);
            }

            u++;

            //last col
            if(u<=d){
                for(int i=u;i<=d;i++){
                    ans.push_back(matrix[i][r]);
                }
            }


            r--;

            //last row
            if(u<=d){
                 for(int i=r;i>=l;i--){
                   ans.push_back(matrix[d][i]);
                 }
                 d--;
            }


            //first col

            if(l<=r){
                for(int i=d;i>=u;i--){
                    ans.push_back(matrix[i][l]);
                }

                l++;
            }
        }


        return ans;

    }
};