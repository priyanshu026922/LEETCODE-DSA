class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        
       sort(begin(s),end(s));
       sort(begin(t),end(t));
       if(s==t)return true;
       return false;
    }
};