class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int ans=0;
         int last=0;
         for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1'){
                    count++;
                }
            }
            if(count==0)continue;
            ans+=(last*count);
          last=count;
         }
         return ans;
    }
};