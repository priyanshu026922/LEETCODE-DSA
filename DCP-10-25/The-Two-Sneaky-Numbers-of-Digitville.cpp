class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size()-2;
       
       int x=0;
       //saare nums ka element ka XOR
       for(int y:nums){
             x^=y;
       }
       
       //saare expected range of values ka XOR;
       //elements repeated twice ----would have got cancelled during the previous for-loop-->as( a^a==0);

       //so taking XOR of expected elements would bring back the repeated elements---(take a dry run --->willl understand easily)
        for(int i=0;i<=n-1;i++){
            x^=i;
        }

       int trailing_zeroes=__builtin_ctz(x);
       int mask=1<<trailing_zeroes;
       int g1=0;
       int g2=0;
       
       for(int num:nums){
        if(num&mask){
            g1^=num;
        }else{
            g2^=num;
        }
       }
      for(int i=0;i<=n-1;i++){
        if(i&mask){
            g1^=i;
        }else{
            g2^=i;
        }
       }

        return {g1,g2};
    }
};