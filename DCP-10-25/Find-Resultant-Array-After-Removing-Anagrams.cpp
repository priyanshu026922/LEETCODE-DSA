class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
      
        int n=words.size();
    //     for(int i=1;i<n;i++){
    //         sort(begin(words[i]),end(words[i]));
    //     }
    // sort(begin(words),end(words));
    vector<string>ans;
    ans.push_back(words[0]);
       for(int i=1;i<n;i++){
             string x=words[i];
             string y=words[i-1];
             sort(begin(x),end(x));
             sort(begin(y),end(y));
             if(x!=y){
                ans.push_back(words[i]);
             }
       }
       return ans;
    }
};