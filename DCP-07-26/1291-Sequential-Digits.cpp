class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        
        //till 100:12,23,34,45,56,67,78,89,
        //till 200:123
        //till 300:234
        //till 400:345
        //till 500:456
        //till 500-600:567
        //till 600-700:678
        //till 700-800:789
         //till 800-900:no
        //till 900-1000:no
        //..............
        //till 1000-2000:1234
        //till 3000:2345
        ///////till 6000-7 000---->6789
       vector<int>vec={12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,1234,2345,3456,4567,5678,6789,12345,23456,34567,45678,56789,123456,234567,345678,456789,1234567,2345678,3456789,12345678,23456789,123456789};

       int ind1=lower_bound(begin(vec),end(vec),low)-vec.begin();
       int ind2=upper_bound(begin(vec),end(vec),high)-vec.begin();
       
    //    if(vec[ind2]!=high){
    //         ind2--;
    //    }



       for(int i=ind1;i<ind2;i++){
          ans.push_back(vec[i]);
       }
       return ans;
    }
};