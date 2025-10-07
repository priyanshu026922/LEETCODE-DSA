class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(begin(strs),end(strs));
        string ans="";
        for(int i=0;i<min(strs[0].size(),strs[strs.size()-1].size());i++){
            if(strs[0][i]!=strs[strs.size()-1][i]){
                break;
            }
            ans+=strs[0][i];
        }
        return ans;
    }
};