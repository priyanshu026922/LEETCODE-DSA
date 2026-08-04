class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        
        int ans=0;
        int type=1;
        while(n>0){
           
           int x=min(8,n)*type;
        //    cout<<"x::"<<x<<endl;
            
           ans+=x;
        //    cout<<ans<<endl;
           type++;
           n-=8;
          
        }

        return ans;
    }
};