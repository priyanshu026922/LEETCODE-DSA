class Solution {
public:
    int smallestNumber(int n) {
        for(int i=1;i<=10;i++){
            int x=1<<i;
            cout<<x<<endl;
            if(x>n){
                return x-1;
            }
        }
        return 0;
    }
};