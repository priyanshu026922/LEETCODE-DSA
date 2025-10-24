class Solution {
public:


    bool isPos(int x){
        map<int,int>mp;
        while(x>0){
            int t=x%10;
            mp[t]++;
            x=x/10;
        }

        for(auto it:mp){
            if(it.second!=it.first){
                return false;
            }
        }
        return true;
    }


    
    int nextBeautifulNumber(int n) {
        if(n==0)return 1;

        int i=n+1;
       while(i<=1224444){
          if(isPos(i)){
            return i;
          }
          i++;
        }
        return -1;
    }
};