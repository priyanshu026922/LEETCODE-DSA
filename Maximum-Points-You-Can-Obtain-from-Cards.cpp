class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
         int i;
         int sum=0;
         for( i=0;i<k;i++){
               sum+=cardPoints[i];
         }
         int n=cardPoints.size();
         int j=n-1;
        int l=sum;
        int r=0;
        for(int i=k-1;i>=0;i--){
           l-=cardPoints[i];
           r+=cardPoints[j];
           j--;
           sum=max(sum,l+r);
        }
         return sum;
    }
};