class Solution {
public:
    int totalMoney(int n) {
    //     int startMoney=1;
    //     int res=0;
    //    while(n>0){
    //     int money=startMoney;
    //     for(int i=1;i<=min(n,7);i++){
    //            res+=money;
    //            money++;
    //     }
    //     n=n-7;
    //     startMoney++;

    //    }
    //    return res;

    
    int terms=n/7;
    int f=28;
    int l=28+(terms-1)*7;

    int res=terms*(f+l)/2;


    int start=1+terms;

   for(int day=1;day<=(n%7);day++){
    res+=start;
    start++;
   }
   return res;











    }
};