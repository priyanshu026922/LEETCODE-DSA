
bool comp(string &s1,string &s2){
    return s1.size()<s2.size();
}

class Solution {
public:
bool isCorrect(string &s1,string&s2){
    if(s1.length()!=s2.length()+1){
       
        return false;
    }

    int i=0;//for s1
    int j=0;//for s2
    while(i<s1.length()){
        if(j<s2.length()&&s1[i]==s2[j]){
            j++;
        }
        i++;
    }
    if(i==s1.length()&&j==s2.length())return true;
    return false;
}

int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int>dp(n,1);
        
        int maxi=1;

        sort(words.begin(),words.end(),comp);

        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(isCorrect(words[i],words[prev])&&1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                
                }
            }

            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
return maxi;

    }
};