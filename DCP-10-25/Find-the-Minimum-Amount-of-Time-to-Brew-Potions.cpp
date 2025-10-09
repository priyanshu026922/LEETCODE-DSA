class Solution {
public:
typedef long long ll;
    ll minTime(vector<int>& skill, vector<int>& mana) {
      int n=skill.size();
      int m=mana.size();
      
      vector<ll>finishTime(n,0);

     for(int j=0;j<m;j++){
             finishTime[0]+=1LL*mana[j]*skill[0];
             for(int i=1;i<n;i++){
                finishTime[i]=max(finishTime[i],finishTime[i-1])+1LL*mana[j]*skill[i];

             }
             //syncronization of time
             for(int i=n-1;i>0;i--){
                finishTime[i-1]=finishTime[i]-mana[j]*skill[i];
             }
       }

     return finishTime[n-1];



    }
};