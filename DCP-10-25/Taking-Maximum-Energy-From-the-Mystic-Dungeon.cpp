class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
         ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n=energy.size();
        vector<int>sum(n,0);
        sum[0] = energy[0];
        int op=INT_MIN;
        for(int i=n-1; i>=0 ; i--){
            if(i+k<n){
                sum[i] = energy[i] + sum[i+k];
               
            }
            else sum[i]= energy[i];
             op=max(op,sum[i]);
        }
        return op;
    }
};