class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
       

        // for(int i=0;i<n;i++){
        //     int cnt=0;
     
        
        //     for(int j=i;j<n;j++){
        //          

        //           if(cnt==m){
        //             if(j-i+1<len){
        //                 start=i;
        //                 len=j-i+1;
        //             }
        //           }
        //     }
        // }

        unordered_map<char,int>mp;
        for(auto &it:t){
            mp[it]++;
        }

        int i=0;
        int j=0;
        int cnt=0;
        int len=INT_MAX;
        int start=-1;
        while(j<n){
            if(mp[s[j]]>0){
                cnt++;
            }
            mp[s[j]]--;

            while(cnt==m){
                if(j-i+1<len){
                    len=j-i+1;
                    start=i;
                }

                mp[s[i]]++;
                if(mp[s[i]]>0){
                  cnt--;
                }
                i++;
            }
            j++;
        }

        if(start==-1){
            return "";
        }

        return s.substr(start,len);
    }
};