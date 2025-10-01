class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int val=numBottles;
        if(numBottles<numExchange){
            return val;
        }
        while(numBottles>=numExchange){
            val+=(numBottles/numExchange);
            numBottles=(numBottles/numExchange)+(numBottles%numExchange);
        }
        return val;
    }
};