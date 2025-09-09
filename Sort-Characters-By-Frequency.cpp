class Solution {
public:
bool static cmp(pair<char,int>&p1,pair<char,int>&p2){
    if(p1.second>p2.second)return true;
    return false;
}
    string frequencySort(string s) {
        int n=s.length();
        unordered_map<char,int>freq;
         for(int i=0;i<n;i++){
           freq[s[i]]++;
         }
         vector<pair<char,int>>vec(begin(freq),end(freq));
        
         sort(begin(vec),end(vec),cmp);
           string ans="";

           for(int i=0;i<vec.size();i++){
            ans.append(vec[i].second,vec[i].first);
           }

           return ans;
    }
};