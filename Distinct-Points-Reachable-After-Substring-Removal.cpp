class Solution {
public:
    int distinctPoints(string s, int k) {
         int n=s.length();
         set<pair<int,int>>st;
         int x=0,y=0;
         for(int i=0;i<k;i++){
            if(s[i]=='U'){
                y++;
            }else if(s[i]=='D'){
                y--;
            }else if(s[i]=='L'){
                x--;
            }else{
                x++;
            }
         }
         st.insert({x,y});
         for(int i=k;i<n;i++){
            if(s[i-k]=='U'){
                y--;
            }else if(s[i-k]=='D'){
                y++;
            }else if(s[i-k]=='L'){
                x++;
            }else{
                x--;
            }

            if(s[i]=='U'){
                y++;
            }else if(s[i]=='D'){
                y--;
            }else if(s[i]=='L'){
                x--;
            }else{
                x++;
            }
            st.insert({x,y});
         } 
         return st.size();
    }
};