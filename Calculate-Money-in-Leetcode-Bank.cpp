class Solution {
public:
    int totalMoney(int n) {
        int startMoney=1;
        int res=0;
       while(n>0){
        int money=startMoney;
        for(int i=1;i<=min(n,7);i++){
               res+=money;
               money++;
        }
        n=n-7;
        startMoney++;

       }
       return res;
    }
};