class Solution {
public:
    void solve(int low,int high,vector<int>&ans,int num,int last){
        
        if(num>high){
            return;
        }

        if(num>=low&&num<=high){
            ans.push_back(num);
        }

        // int val=num;
        for(int i=1;i<=9;i++){

            if(last==10||(i==last+1)){
                int x=num*10+i;
                // cout<<x<<endl;
                solve(low,high,ans,x,i);
            }
        }


    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        solve(low,high,ans,0,10);
        sort(begin(ans),end(ans));
       return ans;
    }
};