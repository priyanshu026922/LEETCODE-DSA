class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length();
        int mini=0;
        //similar ka sum cummulative lete jaate hai aur maxi wait similar consecutive elemts ke liye
        //isse hoga yeh akhri mai jab siumilar eleemnts khtm ho jaenge toh humlog min cost =sum-maxi krke nikal skte
        //jisko overall min_ans+=min_cost nikalenge
          int sum=neededTime[0];
          char ch=colors[0];
          int maxi=neededTime[0];
            for(int i=1;i<n;i++){
                    if(colors[i]==ch){
                        sum+=neededTime[i];
                        maxi=max(maxi,neededTime[i]);
                    }else{
                        mini+=(sum-maxi);
                        ch=colors[i];
                        sum=neededTime[i];
                        maxi=neededTime[i];
                    }
            }
            mini+=(sum-maxi);
            return mini;
    }
};