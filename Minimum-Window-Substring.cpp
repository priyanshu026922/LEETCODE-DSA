class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length();
        int n=t.length();
        unordered_map<char,int>mp;

        for(int i=0;i<n;i++){
            mp[t[i]]++;
        }
         int sIndex=-1;//start Index
        int minilen=INT_MAX;;
        int i=0;
        int j=0;
        int count=0;
        while(j<m){
            if(mp[s[j]]>0)count++;
            mp[s[j]]--;

            while(count==n){
               if(j-i+1<minilen){
                minilen=j-i+1;
                sIndex=i;
               }
               mp[s[i]]++;
               if(mp[s[i]]>0)count--;
               i++;
            }
            j++;
        //    mp[s[i]]--;
        //    if(mp[s[i]]==0){
        //     mp.erase(s[i]);
        //    }
        //    while(mp.find(s[i])!=mp.end()){
        //       i++;
        //    }
        //    minilen=min(minlen,j-i+1);
        //    j++;
        }
        return sIndex==-1?"":s.substr(sIndex,minilen);
    }
};