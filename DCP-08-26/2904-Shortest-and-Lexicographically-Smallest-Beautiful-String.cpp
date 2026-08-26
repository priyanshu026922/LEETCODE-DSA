class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        
        vector<int>vec;
        for(int i=0;i<n;i++){
            if(s[i]=='1')vec.push_back(i);
        }
        
        if(vec.size()==0||vec.size()<k)return "";
        

        string mini=s;
        int len=n;
        int m=vec.size();
        for(int i=0;i<=m-k;i++){
           int l=vec[i+k-1]-vec[i]+1;
           string x=s.substr(vec[i],vec[i+k-1]-vec[i]+1);
           if(l<len){
              mini=x;
              len=l;
           }else if(l==len){
               mini=min(mini,x);
           }
        }

        return mini;
    }
};