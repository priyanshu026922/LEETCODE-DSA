class Solution {
private:
   int n;
public:
   bool solve(int turn,vector<int>&nums,int p1,int p2,int i,int j){
        if(i>j){
            // if(turn==0)p1+=nums[i];
            // else p2+=nums[i];
            // cout<<p1<<" "<<p2<<endl;
            return p1>=p2;
        }

        if(turn==0){
            return solve(1,nums,p1+nums[i],p2,i+1,j)||solve(1,nums,p1+nums[j],p2,i,j-1);
        }

        return solve(0,nums,p1,p2+nums[i],i+1,j)&&solve(0,nums,p1,p2+nums[j],i,j-1);
   }
   
    bool predictTheWinner(vector<int>& nums) {
        n=nums.size();
        return solve(0,nums,0,0,0,n-1);
    }
};