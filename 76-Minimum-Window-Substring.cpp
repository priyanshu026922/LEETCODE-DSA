class Solution {
public:
    string minWindow(string s, string t) {
         unordered_map<char,int>mp;

         for(char it:t){
           mp[it]++;
         }

         int m=s.length();
         int n=t.length();

         int sInd=-1;
         int mini=INT_MAX;

         int i=0;
         int j=0;
         int cnt=0;
         while(j<m){
             if(mp[s[j]]>0){
                cnt++;
             }

             mp[s[j]]--;


             while(i<m&&cnt==n){
                if(j-i+1<mini){
                    mini=j-i+1;
                    sInd=i;
                }


                mp[s[i]]++;
                if(mp[s[i]]>0){
                    cnt--;
                }
                 i++;
             }

             j++;
         }

        if(sInd==-1)return "";

         return s.substr(sInd,mini);
    }
};