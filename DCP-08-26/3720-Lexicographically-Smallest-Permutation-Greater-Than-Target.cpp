class Solution {
public:
    int n;
    string ans="";
    bool solve(string &s,int i,string curr,string &tar,vector<int>&cnt,bool isInc){
        if(i==n){
            if(isInc){
                ans=curr;
                return true;
            }
            return false;
        }

        for(char ch='a';ch<='z';ch++){
            if(cnt[ch-'a']==0)continue;

            if(isInc==false&&ch<tar[i]){
                continue;
            }
            
            curr+=ch;
            cnt[ch-'a']--;
            bool inc=isInc|(ch>tar[i]);
            if(solve(s,i+1,curr,tar,cnt,inc)){
                return true;
            }
            cnt[ch-'a']++;
            curr.pop_back();
            

        }
        return false;

    }
    string lexGreaterPermutation(string s, string target) {
        n=s.length();
        vector<int>cnt(26,0);
        for(auto &ch:s){
            cnt[ch-'a']++;
        }

        solve(s,0,"",target,cnt,false);

        return ans;
    }
};