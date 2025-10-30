class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
      int count=0;
      int curr=0;
      int prev=0;
      for(int i=0;i<n;i++){
         curr=target[i];
        // if((curr>0&&prev<0)||(curr<0&&prev>0)){
            if(curr>prev){
                count+=(curr-prev);
            }
            
             prev=curr;
        
      }

        //     int mini_val=*min_element(begin(target),end(target));
        //     int count=mini_val;
        //     int maxi=INT_MIN;
        //     for(int i=0;i<n;i++){
        //         if(target[i]==mini_val){
        //             if(maxi!=INT_MIN)count+=(maxi-mini_val);
        //             // cout<<maxi<<" "<<count<<endl;
        //             maxi=INT_MIN;
        //         }else{
        //             maxi=max(maxi,target[i]);
        //         }
        //     }
        // //  cout<<maxi<<" "<<count<<endl;
        //     if(maxi!=INT_MIN)count+=(maxi-mini_val);
        return count;
    }
};