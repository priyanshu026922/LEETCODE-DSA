class Solution {
public:
int largestRecArea(vector<int>&hist){
    stack<int>st;
    int maxA=0;
    int n=hist.size();
    for(int i=0;i<=n;i++){
         while(!st.empty()&&(i==n||hist[st.top()]>hist[i])){
            int h=hist[st.top()];
            st.pop();
            int w;
            if(st.empty()){
                w=i;
            }else{
                w=i-st.top()-1;
              
            }
              maxA=max(maxA,w*h);
           
         }
          st.push(i);
    }
    return maxA;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxA=0;
        vector<int>height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')height[j]++;
                else height[j]=0;
            }
            maxA=max(maxA,largestRecArea(height));
        }
        return maxA;
    }
};