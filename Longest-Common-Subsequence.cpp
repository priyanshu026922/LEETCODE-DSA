class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
       
        vector<int>curr(n2+1,0);
        vector<int>prev(n2+1,0);
        

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                int m=-1e9,nm=-1e9;
                if(text1[i-1]==text2[j-1])  curr[j]=1+prev[j-1];
                else  curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[n2];
    }
};