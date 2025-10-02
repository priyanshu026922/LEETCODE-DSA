class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        if(numBottles<numExchange){
            return numBottles;
        }

        int x=numBottles;
        int y=numExchange;
        int ans=0;
        while(x>=y){
         ans+=y;
               x-=y;
            y=y+1;
            x++;
        }
        return ans+x;
    }
};