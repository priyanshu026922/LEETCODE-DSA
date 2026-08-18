class Solution {
public:
    int maximumGap(string skill, string station) {
        //skill[i] -- represents the skill of worker i, 
        //and station[j] -- represents the skill supported by station j.
        int n=skill.length();
        int m=station.length();

        //station[ji] == skill[i]
        // assigned station indices must be strictly increasing in worker    order, meaning j0 < j1 < ... < jn - 1.
        
        //  1st :
        //assign the current skill to the LEFTMOST index possible :
          vector<int>pref(n);
          vector<int>suff(n);
          int j=0;
          for(int i=0;i<m;i++){
            if(j<n&&skill[j]==station[i]){
                pref[j]=i;
                j++;
            }
           }

           j=n-1;
           for(int i=m-1;i>=0;i--){
        
                if(j>=0&&skill[j]==station[i]){
                    suff[j]=i;
                    j--;
                }
           }



        //2nd :
        //assign the current skill to the RIGHTMOST index possible :

        
        // for(int i=0;i<n;i++){
        //     cout<<pref[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<suff[i]<<" ";
        // }
        int maxi=0;
        for(int i=0;i<n-1;i++){
            
            maxi=max(maxi,abs(pref[i]-suff[i+1]));
        }
        return maxi;
        
        
    }
};