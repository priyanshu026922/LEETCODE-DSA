class Solution {
public:
    bool nozero(int x){
        while(x>0){
            int n=x%10;
            if(n==0)return false;
            x=x/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
    
     for(int i=1;i<=n;i++){
        int x=i;
        int y=n-x;
        if(nozero(x)&&nozero(y)){
            return {x,y};
        }
     }
     return {};
    }
};